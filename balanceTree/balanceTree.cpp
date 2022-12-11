struct Node {
    int data; 
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Dummy Data
dumpData[] = {2, 13, 7, 16, 19, 9, 22, 10, 14, 17}




// Check Tree Balance Function
class isTreeBalance {
    int height; // store the height of the subtrees
    public:
    // Function ot check whether a binary tree is balance or not
    bool isBalanced(Node *root) {
        // Check if the root is NULL, then it's balance
        if (root == NULL) {
            height = 0; // Each time we traverse down the node, we will wewrite the height to 0.
            return true;
        }

        // Check Left Sub Tree
        height = 0; // Declare initial height of Left Node as 0, this is the starting point
        bool isLeftBalanced = isBalanced(root -> left); // Calling isBalance function to check Left Node balance or not
        int leftSubTreeHeight = height; // Store the height of Left Node after we check the depth

        // Check Right Sub Tree
        height = 0; // Declare initial height of Right Node as 0, this is the starting point
        bool isRightBalanced = isBalanced(root -> right); // Calling isBalance function to check Right Node balance or not
        int rightSubTreeHeight = height; // Store the height of Right Node after we check the depth

        // Check the height of all sub tree
        height = max(leftSubTreeHeight, rightSubTreeHeight) + 1; // + 1 for current Node we pivot to count other Nodes

        // Check Left Node and Right Node are balance
        if(isLeftBalanced && isRightBalanced && abs(rightSubTreeHeight - leftSubTreeHeight) <= 1) {
            return true; // if Left node and Right Node is Balance and the Height of the tree is balance, we return true
        }
        return false; // if the tree is not balance we return false
    }
};

// Insert into Tree Function

// Search Tree Function
class searchInTree {
    public:
        int binarySearch(int arr[], int n, int k) {

        }
}

