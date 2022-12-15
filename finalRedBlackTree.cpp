// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

// Create instance of Main Tree
struct Node {
  int data;
  Node *parent;
  Node *leftNode;
  Node *rightNode;
  int color;
};
typedef Node *NodePtr;


 // Create Class for Red-Black Tree and Logics
class RedBlackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

  // Create Tree Node with NULL value, as starting we create a NULL root
  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->leftNode = nullptr;
    node->rightNode = nullptr;
    node->color = 0;
  }

  // Preorder
  void preOrderHelper(NodePtr node) {
    if (node != TNULL) {
      cout << node->data << " ";
      preOrderHelper(node->leftNode);
      preOrderHelper(node->rightNode);
    }
  }

  // Inorder
  void inOrderHelper(NodePtr node) {
    if (node != TNULL) {
      inOrderHelper(node->leftNode);
      cout << node->data << " ";
      inOrderHelper(node->rightNode);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node) {
    if (node != TNULL) {
      postOrderHelper(node->leftNode);
      postOrderHelper(node->rightNode);
      cout << node->data << " ";
    }
  }



  NodePtr searchTreeHelper(NodePtr node, int key) {
    if (node == TNULL || key == node->data) {
      return node;
    }

    if (key < node->data) {
      return searchTreeHelper(node->leftNode, key);
    }
    return searchTreeHelper(node->rightNode, key);
  }

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u == u->parent->leftNode) {
      u->parent->leftNode = v;
    } else {
      u->parent->rightNode = v;
    }
    v->parent = u->parent;
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
      if (k->parent == k->parent->parent->rightNode) {
        u = k->parent->parent->leftNode;
        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->leftNode) {
            k = k->parent;
            rightNodeRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftNodeRotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->rightNode;

        if (u->color == 1) {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        } else {
          if (k == k->parent->rightNode) {
            k = k->parent;
            leftNodeRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightNodeRotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = 0;
  }

  void printHelper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      printHelper(root->leftNode, indent, false);
      printHelper(root->rightNode, indent, true);
    }
  }

   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->leftNode = nullptr;
    TNULL->rightNode = nullptr;
    root = TNULL;
  }

  void preorder() {
    preOrderHelper(this->root);
  }

  void inorder() {
    inOrderHelper(this->root);
  }

  void postorder() {
    postOrderHelper(this->root);
  }

  NodePtr searchTree(int k) {
    return searchTreeHelper(this->root, k);
  }

  NodePtr minimum(NodePtr node) {
    while (node->leftNode != TNULL) {
      node = node->leftNode;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->rightNode != TNULL) {
      node = node->rightNode;
    }
    return node;
  }

  NodePtr successor(NodePtr x) {
    if (x->rightNode != TNULL) {
      return minimum(x->rightNode);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->rightNode) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x) {
    if (x->leftNode != TNULL) {
      return maximum(x->leftNode);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->leftNode) {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftNodeRotate(NodePtr x) {
    NodePtr y = x->rightNode;
    x->rightNode = y->leftNode;
    if (y->leftNode != TNULL) {
      y->leftNode->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->leftNode) {
      x->parent->leftNode = y;
    } else {
      x->parent->rightNode = y;
    }
    y->leftNode = x;
    x->parent = y;
  }

  void rightNodeRotate(NodePtr x) {
    NodePtr y = x->leftNode;
    x->leftNode = y->rightNode;
    if (y->rightNode != TNULL) {
      y->rightNode->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
      this->root = y;
    } else if (x == x->parent->rightNode) {
      x->parent->rightNode = y;
    } else {
      x->parent->leftNode = y;
    }
    y->rightNode = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(int key) {
    NodePtr node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->leftNode = TNULL;
    node->rightNode = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL) {
      y = x;
      if (node->data < x->data) {
        x = x->leftNode;
      } else {
        x = x->rightNode;
      }
    }

    node->parent = y;
    if (y == nullptr) {
      root = node;
    } else if (node->data < y->data) {
      y->leftNode = node;
    } else {
      y->rightNode = node;
    }

    if (node->parent == nullptr) {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr) {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot() {
    return this->root;
  }

  void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }
};


int main() {
// Dummy Data
int dumpData[10] = {13, 7, 16, 19, 9, 22, 10, 14, 17};

  RedBlackTree bst;

    for(int data : dumpData) {
        bst.insert(data);
    }
    bst.printTree();

//   bst.insert(55);
//   bst.insert(40);
//   bst.insert(65);
//   bst.insert(60);
//   bst.insert(75);
//   bst.insert(57);

//   bst.printTree();
}