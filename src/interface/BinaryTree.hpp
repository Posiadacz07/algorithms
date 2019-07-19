#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <vector>

namespace trees {
//! Binary tree class
class BinaryTree {
public:
  BinaryTree() : rootNode(nullptr) {}
  ~BinaryTree();

  //! Inner class for node in binary tree with int key value
  class Node {
  public:
    //! Getter of node key.
    //! returns integer key of current node
    int getKey() const;

    //! Getter of left child of current node.
    //! returns pointer to node which is left child of current node
    Node *getLeftChild() const;

    //! Getter of right child of current node.
    //! returns pointer to node which is right child of current node
    Node *getRightChild() const;

  private:
    Node(int nodeKey) : key(nodeKey), leftChild(nullptr), rightChild(nullptr) {}

    //! Setter of left child of current node.
    //! param[in] newLeftChild pointer to Node that's left child of current node
    //! NOTE: If current node has left child it will be deleted with all their
    //!       children.
    void setLeftChild(Node *newLeftChild);

    //! Setter of right child of current node.
    //! param[in] newRightChild pointer to Node that's right child of current
    //!           node
    //! NOTE: If current node has right child it will be deleted with all their
    //!       children.
    void setRightChild(Node *newRightChild);

    int key;
    Node *leftChild;
    Node *rightChild;

    friend class BinaryTree;
  };

  //! Getter of root node in BinaryTree
  //! returns pointer to rootNode
  Node *getRootNode() const;

  //! Setter of root node in BinaryTree
  //! param[in] key key of root node to set
  //! returns   pointer to already set node
  //! NOTE: If root node exists it will be deleted with all their children.
  Node *setRootNode(int key);
  Node *insertLeftChild(Node *currentNode, int key);
  Node *insertRightChild(Node *currentNode, int key);

  //! Search for node with given key in current binary tree.
  //! param[in] key value of key for searching node
  //! returns   pointer to Node with given key if node exists, nullptr
  //!           otherwise
  Node *findNode(int key);

  //! Search for ancestors of given node key in curren binary tree.
  //! param[in] key of the node to find ancestors
  //! returns   collection of keys for all the ancestors of the node with given
  //!           key
  std::vector<int> findAncestors(int key);

  //! Search for lowest common ancestor in curren binary tree.
  //! param[in] firstNode reference to first node
  //! param[in] secondNode reference to second node
  //! returns   pointer to node that is lowest common ancestor given two nodes
  //!           if exists, nullptr otherwise
  Node *lowestCommonAncestor(Node *firstNode, Node *secondNode);

private:
  Node *rootNode;
};
} // namespace trees
#endif // BINARY_TREE_HPP