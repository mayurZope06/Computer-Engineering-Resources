// Create a binary search tree from an empty tree by inserting values in a given order. Then, perform operations like
// inserting a new node, finding the number of nodes in the longest path, finding the minimum data value, swapping
// left and right pointers, and searching for a value.\
// (Binary Search Tree)
#include <iostream>

using namespace std;

// Structure for a Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Class for Binary Search Tree
class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a node into the BST
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Function to insert a node into the BST
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    // Find the number of nodes in the longest path from root
    int longestPath() {
        return longestPathHelper(root);
    }

    int longestPathHelper(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = longestPathHelper(node->left);
        int rightDepth = longestPathHelper(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    // Find the minimum value in the BST
    int findMinValue() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        return findMinValueHelper(root);
    }

    int findMinValueHelper(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    // Swap left and right pointers at every node
    void swapChildren() {
        swapChildrenHelper(root);
    }

    void swapChildrenHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        swap(node->left, node->right);
        swapChildrenHelper(node->left);
        swapChildrenHelper(node->right);
    }

    // Search for a value in the BST
    bool search(int value) {
        return searchHelper(root, value);
    }

    bool searchHelper(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }

    // Function to print the tree in-order (for visualization)
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }
};

int main() {
    BinarySearchTree tree;

    int n, value;
    cout << "Enter number of elements to insert into BST: ";
    cin >> n;

    cout << "Enter " << n << " values to insert into BST: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    cout << "In-order traversal of the tree: ";
    tree.inorder();

    // i. Insert a new node
    cout << "Enter a value to insert into the tree: ";
    cin >> value;
    tree.insert(value);
    cout << "In-order traversal after inserting new node: ";
    tree.inorder();

    // ii. Find the number of nodes in the longest path from root
    cout << "Number of nodes in the longest path from root: " << tree.longestPath() << endl;

    // iii. Minimum data value found in the tree
    cout << "Minimum value in the tree: " << tree.findMinValue() << endl;

    // iv. Change the tree so that the roles of the left and right pointers are swapped at every node
    tree.swapChildren();
    cout << "In-order traversal after swapping left and right pointers: ";
    tree.inorder();

    // v. Search for a specific value
    cout << "Enter a value to search in the tree: ";
    cin >> value;
    if (tree.search(value)) {
        cout << "Value " << value << " found in the tree." << endl;
    } else {
        cout << "Value " << value << " not found in the tree." << endl;
    }

    return 0;
}

// #include <iostream>
// #include <cstdlib>
// using namespace std;

// // Node structure for binary search tree
// struct Node {
//     int data;
//     Node* left;
//     Node* right;

//     Node(int value) : data(value), left(nullptr), right(nullptr) {}
// };

// // Function to insert a new node into a binary search tree
// Node* insert(Node* root, int value) {
//     if (root == nullptr) {
//         return new Node(value);
//     }

//     if (value < root->data) {
//         root->left = insert(root->left, value);
//     } else {
//         root->right = insert(root->right, value);
//     }

//     return root;
// }

// // Function to find the number of nodes in the longest path from the root
// int findLongestPath(Node* root) {
//     if (root == nullptr) {
//         return 0;
//     }

//     int leftPath = findLongestPath(root->left);
//     int rightPath = findLongestPath(root->right);

//     return max(leftPath, rightPath) + 1;
// }

// // Function to find the minimum data value in a binary search tree
// int findMinValue(Node* root) {
//     if (root->left == nullptr) {
//         return root->data;
//     }

//     return findMinValue(root->left);
// }

// // Function to swap the left and right pointers of all nodes in a binary tree
// void swapPointers(Node* root) {
//     if (root == nullptr) {
//         return;
//     }

//     swapPointers(root->left);
//     swapPointers(root->right);

//     swap(root->left, root->right);
// }

// // Function to search for a value in a binary search tree
// bool searchValue(Node* root, int value) {
//     if (root == nullptr) {
//         return false;
//     }

//     if (root->data == value) {
//         return true;
//     } else if (value < root->data) {
//         return searchValue(root->left, value);
//     } else {
//         return searchValue(root->right, value);
//     }
// }

// // Function to perform in-order traversal of a binary search tree
// void inorderTraversal(Node* root) {
//     if (root == nullptr) {
//         return;
//     }

//     inorderTraversal(root->left);
//     cout << root->data << " ";
//     inorderTraversal(root->right);
// }

// int main() {
//     Node* root = nullptr;

//     int choice;
//     while (true) {
//         cout << "\nBinary Search Tree Menu:\n";
//         cout << "1. Insert a value\n";
//         cout << "2. Find the number of nodes in the longest path from the root\n";
//         cout << "3. Find the minimum data value in the tree\n";
//         cout << "4. Swap the left and right pointers of all nodes\n";
//         cout << "5. Search for a value\n";
//         cout << "6. Print the tree (in-order traversal)\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 int value;
//                 cout << "Enter the value to insert: ";
//                 cin >> value;
//                 root = insert(root, value);
//                 cout << "Value inserted successfully.\n";
//                 break;
//             }
//             case 2: {
//                 int longestPath = findLongestPath(root);
//                 cout << "Number of nodes in the longest path from the root: " << longestPath << endl;
//                 break;
//             }
//             case 3: {
//                 int minValue = findMinValue(root);
//                 cout << "Minimum data value found in the tree: " << minValue << endl;
//                 break;
//             }
//             case 4: {
//                 swapPointers(root);
//                 cout << "Pointers swapped successfully.\n";
//                 break;
//             }
//             case 5: {
//                 int value;
//                 cout << "Enter the value to search: ";
//                 cin >> value;
//                 bool found = searchValue(root, value);
//                 if (found) {
//                     cout << "Value " << value << " found in the tree.\n";
//                 } else {
//                     cout << "Value " << value << " not found in the tree.\n";
//                 }
//                 break;
//             }
//             case 6: {
//                 cout << "Binary Search Tree (in-order traversal): ";
//                 inorderTraversal(root);
//                 cout << endl;
//                 break;
//             }
//             case 7: {
//                 cout << "Exiting...\n";
//                 exit(0);
//             }
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//                 break;
//         }
//     }
// }
