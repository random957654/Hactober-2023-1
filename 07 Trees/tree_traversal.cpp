#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Inorder Traversal: Left, Root, Right
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Preorder Traversal: Root, Left, Right
void preorderTraversal(TreeNode* root) {
    if (root) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder Traversal: Left, Right, Root
void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform tree traversals
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (real applications should use proper memory management)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
