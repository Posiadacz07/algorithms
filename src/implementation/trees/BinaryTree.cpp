#include "../../interface/BinaryTree.hpp"
#include <memory>

namespace trees {

Node::Node(int newNodeValue) : nodeValue(newNodeValue) {}

BinaryTree::BinaryTree(int value) : rootNode(std::make_unique<Node>(value)) {}
BinaryTree::~BinaryTree() {}
void BinaryTree::insertNode(int nodeValue) {}
bool BinaryTree::searchNode(int nodeValue) {}

} // namespace trees