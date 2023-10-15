#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        while (root->right) {
            root = root->right;
        }
        
        root->right = right;
    }
};

// Helper function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root) {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution solution;
    solution.flatten(root);

    // Print the flattened tree
    printFlattenedTree(root);

    // Clean up memory (deallocate tree nodes)
    // Implement this part according to your specific memory management strategy.
    
    return 0;
}
