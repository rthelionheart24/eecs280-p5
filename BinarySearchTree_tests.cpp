#include "BinarySearchTree.h"
#include "unit_test_framework.h"

TEST(test_empty)
{
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());
}

TEST(test_size)
{

    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.size(), 0u);

    tree.insert(3);
    ASSERT_EQUAL(tree.size(), 1u);

    tree.insert(5);
    ASSERT_EQUAL(tree.size(), 2u);
}

TEST(test_height)
{

    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.height(), 0u);

    tree.insert(5);
    ASSERT_EQUAL(tree.height(), 1u);

    tree.insert(1);
    ASSERT_EQUAL(tree.height(), 2u);

    tree.insert(6);
    ASSERT_EQUAL(tree.height(), 2u);
}

TEST(test_copy_nodes)
{

    BinarySearchTree<int> tree;
    BinarySearchTree<int> t2 = tree;

    ASSERT_EQUAL(t2.height(), 0u)

    tree.insert(3);
    tree.insert(5);
    BinarySearchTree<int> t1 = tree;

    ASSERT_EQUAL(t1.height(), 2u);
    ASSERT_EQUAL(t1.size(), 2u);
    ASSERT_EQUAL(*t1.begin(), 3);
}

TEST(test_traverse_preorder)
{
    BinarySearchTree<int> tree;

    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);
}

TEST(test_traverse_inorder)
{
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);
}

TEST(test_sorting_invariant)
{
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_TRUE(tree.check_sorting_invariant());

    *tree.begin() = 20;

    ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(test_begin)
{
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(*tree.begin(), 0);
}

TEST(test_end)
{
    BinarySearchTree<int> tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(++tree.find(10), tree.end());
}

TEST(test_min_element)
{
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.min_element(), tree.end());

    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(*tree.min_element(), 0);
}

TEST(test_max_element)
{
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.max_element(), tree.end());

    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(*tree.max_element(), 10);
}

TEST(test_min_greater_than)
{
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.min_greater_than(10), tree.end());

    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(*tree.min_greater_than(0), 1);
    ASSERT_EQUAL(*tree.min_greater_than(8), 10);
    ASSERT_EQUAL(*tree.min_greater_than(7), 8);
}

TEST(test_find)
{
    BinarySearchTree<int> tree;

    ASSERT_EQUAL(tree.find(1), tree.end());

    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(10);

    ASSERT_EQUAL(tree.find(20), tree.end());
    ASSERT_EQUAL(*tree.find(10), 10);
}

TEST(test_insert)
{

    BinarySearchTree<int> tree;
    tree.insert(4);
    ASSERT_EQUAL(tree.size(), 1);
    ASSERT_EQUAL(tree.height(), 1);
    ASSERT_EQUAL(*tree.begin(), 4);

    tree.insert(5);
    ASSERT_EQUAL(*(++tree.begin()), 5);
    ASSERT_EQUAL(tree.height(), 2);

    tree.insert(1);
    ASSERT_EQUAL(*tree.begin(), 1);
}

TEST_MAIN()
