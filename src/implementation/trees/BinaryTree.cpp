#include "../interface/BinaryTree.hpp"

namespace trees {
int BinaryTree::Node::getKey() const { return key; }

BinaryTree::Node *BinaryTree::Node::getLeftChild() const { return leftChild; }

BinaryTree::Node *BinaryTree::Node::getRightChild() const { return rightChild; }

// Helper function to remove current node with all their children.
void remove(BinaryTree::Node *currentNode) {
  if (currentNode == nullptr) {
    return;
  }
  remove(currentNode->getLeftChild());
  remove(currentNode->getRightChild());
  delete currentNode;
}

void BinaryTree::Node::setLeftChild(Node *newLeftChild) {
  remove(leftChild);
  leftChild = newLeftChild;
}

void BinaryTree::Node::setRightChild(Node *newRightChild) {
  remove(rightChild);
  rightChild = newRightChild;
}

BinaryTree::Node *BinaryTree::getRootNode() const { return rootNode; }

BinaryTree::Node *BinaryTree::setRootNode(int key) {
  BinaryTree::Node *newNode = new BinaryTree::Node(key);
  remove(rootNode);
  rootNode = newNode;
  return newNode;
}

BinaryTree::Node *BinaryTree::insertLeftChild(BinaryTree::Node *currentNode,
                                              int key) {
  BinaryTree::Node *newNode = new BinaryTree::Node(key);
  currentNode->setLeftChild(newNode);
  return newNode;
}

BinaryTree::Node *BinaryTree::insertRightChild(BinaryTree::Node *currentNode,
                                               int key) {
  BinaryTree::Node *newNode = new BinaryTree::Node(key);
  currentNode->setRightChild(newNode);
  return newNode;
}

// Helper function to find node with given key or find ancestors of node with
// given key.
BinaryTree::Node *findNodeAndAncestors(BinaryTree::Node *currentRootNode,
                                       int key,
                                       std::vector<int> *ancestors = nullptr) {
  if (currentRootNode == nullptr) {
    return nullptr;
  }

  if (currentRootNode->getKey() == key) {
    return currentRootNode;
  } else {
    BinaryTree::Node *findNode =
        findNodeAndAncestors(currentRootNode->getLeftChild(), key, ancestors);

    if (findNode == nullptr) {
      findNode = findNodeAndAncestors(currentRootNode->getRightChild(), key,
                                      ancestors);
    }

    if (findNode != nullptr) {
      if (ancestors != nullptr) {
        ancestors->push_back(currentRootNode->getKey());
      }
      return findNode;
    } else {
      return nullptr;
    }
  }
}

BinaryTree::Node *BinaryTree::findNode(int key) {
  return findNodeAndAncestors(getRootNode(), key);
}

std::vector<int> BinaryTree::findAncestors(int key) {
  BinaryTree::Node *root = getRootNode();
  std::vector<int> ancestors;
  findNodeAndAncestors(root, key, &ancestors);
  return ancestors;
}

// Helper function to find lowest common ancestor - traversing tree
BinaryTree::Node *lowestCommonAncestorImpl(BinaryTree::Node *rootNode,
                                           int firstNodeKey,
                                           int secondNodeKey) {
  if (rootNode == nullptr) {
    return nullptr;
  }

  if (rootNode->getKey() == firstNodeKey ||
      rootNode->getKey() == secondNodeKey) {
    return rootNode;
  }

  BinaryTree::Node *leftLowestCommonAncestor = nullptr;
  BinaryTree::Node *rightLowestCommonAncestor = nullptr;
  if (rootNode->getLeftChild() != nullptr) {
    leftLowestCommonAncestor = lowestCommonAncestorImpl(
        rootNode->getLeftChild(), firstNodeKey, secondNodeKey);
  }

  if (rootNode->getRightChild() != nullptr) {
    rightLowestCommonAncestor = lowestCommonAncestorImpl(
        rootNode->getRightChild(), firstNodeKey, secondNodeKey);
  }

  if (leftLowestCommonAncestor != nullptr &&
      rightLowestCommonAncestor != nullptr) {
    return rootNode;
  }

  if (leftLowestCommonAncestor != nullptr) {
    return leftLowestCommonAncestor;
  }
  return rightLowestCommonAncestor;
}

BinaryTree::Node *
BinaryTree::lowestCommonAncestor(BinaryTree::Node *firstNode,
                                 BinaryTree::Node *secondNode) {
  if (firstNode == nullptr || secondNode == nullptr) {
    return nullptr;
  }

  return lowestCommonAncestorImpl(getRootNode(), firstNode->getKey(),
                                  secondNode->getKey());
}

BinaryTree::~BinaryTree() { remove(rootNode); }
} // namespace trees
