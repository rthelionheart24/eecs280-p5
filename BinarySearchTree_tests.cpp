// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"


TEST(test_empty) {
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty());

}

TEST(test_size){

    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.size(),0u);
    tree.insert(3);
    ASSERT_EQUAL(tree.size(),1u);
}

TEST(test_height){


    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.height(),0u);
    tree.insert(5);
    ASSERT_EQUAL(tree.height(),1u);
}

TEST(test_copy_nodes){


    BinarySearchTree<int> tree;
    tree.insert(3);
    Node *n1 =
}

TEST_MAIN()
