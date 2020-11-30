#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
#include "BinarySearchTree.h"
#include "csvstream.h"

using namespace std;

class classifier
{

public:
    classifier();
    ~classifier();

    //EFFECT: Train the classifier with the training set provided
    void train(csvstream &in_train)
    {

        map<string, string> temp;
        set<string> unique_set;
        while (in_train >> temp)
        {
            set<string> unique = unique_words(temp["content"]);
            string tag = temp["tag"];

            //Count the number of posts in total
            num_posts++;

            //Count the number if unique words
            unique_set.insert(unique.begin(), unique.end());

            //For each word w, the number of posts in the entire set that contains w
            for (auto &i : unique)
                num_posts_contain_w[i]++;

            num_posts_with_C[tag]++;

            for (auto &i : unique)
                num_posts_C_w[{tag, i}]++;
        }

        //Count the number if unique words
        vocab_size = unique_set.size();
    }

    //EFFECT: Test the accuracy of the classifier with the testing set provided
    map<string, string> &test(csvstream &in_test)
    {

        map<string, string> temp;
        map<string, double> probability;
        map<string, string> &results;

        while (in_test >> temp)
        {

            string content = temp["content"];
            double highest = 0.0;

            for (auto &i : num_posts_with_C)
            {
                double p = compute(i.first);
                if (p > highest)
                {
                    highest = p;
                    results[content] = p;
                }
            }
        }
    }

    int get_num_posts()
    {
        return num_posts;
    }

    int get_vocab_size()
    {
        return vocab_size;
    }

private:
    //EFFECT: Compute the log-probability score with the given label
    double compute(string C)
    {
        double result = compute_log_prior(C);
        for (auto &i : num_posts_contain_w)
        {
            result += compute_log_likelihood(C, i.first);
        }
        return result;
    }

    //EFFECT: Compute the log prior of a given label C
    double compute_log_prior(string C)
    {
        return log(num_posts_with_C[C] / num_posts);
    }

    //EFFECT: Compute the log_likelihood of a word w given label C
    double compute_log_likelihood(string C, string w)
    {

        if (num_posts_contain_w[w] == 0)
            return log(1 / num_posts);
        if (num_posts_C_w[{C, w}] == 0)
            return log(num_posts_contain_w[w] / num_posts);

        return log(num_posts_C_w[{C, w}] / num_posts_with_C[C]);
    }

private:
    //Total number of training posts;
    int num_posts;

    //Number of unique words in training posts
    int vocab_size;

    //Number of posts containing w
    map<string, int> num_posts_contain_w;

    //Number of posts with different labels
    map<string, int> num_posts_with_C;

    //Number of posts with label C that contains w
    map<pair<string, string>, int> num_posts_C_w;
};

set<string> unique_words(const string &str);
void summary(classifier piazza, int argc);

int main(int argc, const char *argv[])
{
    cout.precision(3);

    if (argc < 3)
    {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }
    if (argc == 4 && strcmp(argv[3], "--debug") != 0)
    {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        return 1;
    }

    string train_file = argv[1], test_file = argv[2];
    csvstream in_train(train_file), in_test(test_file);
    classifier piazza;

    piazza.train(in_train);
    map<string, string> results = piazza.test(in_test);

    return 0;
}

void output(int argc)
{
    if (argc == 4)
}

set<string> unique_words(const string &str)
{
    istringstream source(str);
    set<string> words;
    string word;

    while (source >> word)
    {
        words.insert(word);
    }

    return words;
}

void summary(classifier piazza, map<string, string> &results,
             csvstream &in_train, csvstreaem &in_test, int argc)
{

    if (argc == 4)
    {

        cout << "training data:" << endl;
        map<string, string> temp;
        while (in_train >> temp)
        {
            cout << "label = " << temp["tag"] << ", content = " << temp["content"] << endl;
        }
    }

    cout << "trained on " << piazza.get_num_posts() << " examples" << endl;

    if (argc == 4)
    {
        cout << "vocabulary size = " << piazza.get_vocab_size() << endl
             << endl;

        cout << "classes:" << endl;
        cout << temp["tag"] << ", " << ;
    }
}
