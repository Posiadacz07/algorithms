#include "../src/interface/BinaryTree.hpp"
#include "gtest/gtest.h"

#include <vector>

namespace trees {
namespace test {

class BinaryTreeTest : public ::testing::Test {
public:
  virtual void SetUp() override;
  virtual void TearDown() override;
};

void BinaryTreeTest::SetUp() {}

void BinaryTreeTest::TearDown() {}

// Helper function to set up tree for tests.
//
//            7
//          /   \ 
//         3     4
//        / \     \  
//       2   5     8
//      / \ 
//     1   6
//
BinaryTree prepareBinaryTree() {
  BinaryTree tree;

  BinaryTree::Node *root = tree.setRootNode(7);
  tree.insertLeftChild(root, 3);
  tree.insertRightChild(root, 4);
  tree.insertLeftChild(root->getLeftChild(), 2);
  tree.insertRightChild(root->getLeftChild(), 5);
  tree.insertRightChild(root->getRightChild(), 8);
  tree.insertLeftChild(root->getLeftChild()->getLeftChild(), 1);
  tree.insertRightChild(root->getLeftChild()->getLeftChild(), 6);

  return tree;
}

TEST_F(BinaryTreeTest, FindNodeInTree) {
  BinaryTree tree = prepareBinaryTree();
  BinaryTree::Node *findedNode = tree.findNode(5);
  EXPECT_FALSE(findedNode == nullptr);
  EXPECT_EQ(5, findedNode->getKey());
  EXPECT_TRUE(findedNode->getLeftChild() == nullptr);
  EXPECT_TRUE(findedNode->getRightChild() == nullptr);
}

TEST_F(BinaryTreeTest, FindNodeWithKeyNotExistingInTree) {
  BinaryTree tree = prepareBinaryTree();
  BinaryTree::Node *findedNode = tree.findNode(100);
  EXPECT_TRUE(findedNode == nullptr);
}

TEST_F(BinaryTreeTest, FindNodeInEmptyTree) {
  BinaryTree tree;
  BinaryTree::Node *findedNode = tree.findNode(100);
  EXPECT_TRUE(findedNode);
}

TEST_F(BinaryTreeTest, FindAncestorsInTree) {
  BinaryTree tree = prepareBinaryTree();
  std::vector<int> ancestors = tree.findAncestors(8);
  std::vector<int> expectedAncestors{4, 7};
  EXPECT_EQ(expectedAncestors, ancestors);
}

TEST_F(BinaryTreeTest, FindAncestorsOfRoot) {
  BinaryTree tree = prepareBinaryTree();
  std::vector<int> ancestors = tree.findAncestors(7);
  std::vector<int> expectedAncestors;
  EXPECT_EQ(expectedAncestors, ancestors);
}

TEST_F(BinaryTreeTest, FindAncestorsInEmptyTree) {
  BinaryTree tree;
  std::vector<int> ancestors = tree.findAncestors(8);
  std::vector<int> expectedAncestors;
  EXPECT_EQ(expectedAncestors, ancestors);
}

TEST_F(BinaryTreeTest, FindLowestCommonAncestorInTree) {
  BinaryTree tree = prepareBinaryTree();
  BinaryTree::Node *firstNode = tree.findNode(5);
  BinaryTree::Node *secondNode = tree.findNode(6);
  BinaryTree::Node *lowestCommonAncestor =
      tree.lowestCommonAncestor(firstNode, secondNode);
  EXPECT_EQ(3, lowestCommonAncestor->getKey());
}

TEST_F(BinaryTreeTest, FindLowestCommonAncestorInTreeWithRoot) {
  BinaryTree tree = prepareBinaryTree();
  BinaryTree::Node *firstNode = tree.findNode(7);
  BinaryTree::Node *secondNode = tree.findNode(6);
  BinaryTree::Node *lowestCommonAncestor =
      tree.lowestCommonAncestor(firstNode, secondNode);
  EXPECT_EQ(7, lowestCommonAncestor->getKey());
}

TEST_F(BinaryTreeTest, FindLowestCommonAncestorInTreeWithNotExistingNode) {
  BinaryTree tree = prepareBinaryTree();
  BinaryTree::Node *firstNode = tree.findNode(100);
  EXPECT_TRUE(firstNode == nullptr);
  BinaryTree::Node *secondNode = tree.findNode(6);
  EXPECT_FALSE(secondNode == nullptr);
  BinaryTree::Node *lowestCommonAncestor =
      tree.lowestCommonAncestor(firstNode, secondNode);
  EXPECT_TRUE(lowestCommonAncestor == nullptr);
}
} // namespace test
} // namespace trees