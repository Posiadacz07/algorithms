#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <memory>

namespace trees {

class Node {
public:
  Node(int newNodeValue);
  int nodeValue;
  std::unique_ptr<Node> leftNode;
  std::unique_ptr<Node> rightNode;
};

class BinaryTree {
public:
  BinaryTree(int value);
  ~BinaryTree();

  void insertNode(int nodeValue);
  bool searchNode(int nodeValue);

private:
  std::unique_ptr<Node> rootNode;
};

} // namespace trees

#endif // BINARY_TREE_H