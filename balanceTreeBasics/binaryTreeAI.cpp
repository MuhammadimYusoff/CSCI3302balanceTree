#include <iostream>
#include <algorithm> // for std::max

// define a node for the binary tree
struct Node {
  int data;
  Node *left;
  Node *right;
  int height;
};

// get the height of a given node
int getHeight(Node *node) {
  if (!node) return 0;
  return node->height;
}

// get the balance factor of a given node
int getBalanceFactor(Node *node) {
  if (!node) return 0;
  return getHeight(node->left) - getHeight(node->right);
}

// perform a right rotation on a given node
Node *rightRotate(Node *node) {
  Node *temp = node->left;
  node->left = temp->right;
  temp->right = node;

  // update the heights of the rotated nodes
  node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
  temp->height = 1 + std::max(getHeight(temp->left), getHeight(temp->right));

  // return the new root of the subtree
  return temp;
}

// perform a left rotation on a given node
Node *leftRotate(Node *node) {
  Node *temp = node->right;
  node->right = temp->left;
  temp->left = node;

  // update the heights of the rotated nodes
  node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
  temp->height = 1 + std::max(getHeight(temp->left), getHeight(temp->right));

  // return the new root of the subtree
  return temp;
}

// insert a new node into the binary tree
Node *insert(Node *node, int data) {
  // insert the new node as usual in a binary search tree
  if (!node) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = nullptr;
    temp->height = 1;
    return temp;
  }
  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(
