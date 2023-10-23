#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // They are identical if both trees are empty
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    // they are not identical if one tree is empty
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    // Check if the current nodes have the same value and recursively check their subtrees.
    return (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right);
}

TreeNode* buildTree() {
    int data;
    std::cin >> data;
    if (data == -1) {
        return nullptr; // Return null for empty node
    }
    TreeNode* newNode = new TreeNode(data);
    std::cout << "Enter left child of " << data << " (-1 for no child): ";
    newNode->left = buildTree();
    std::cout << "Enter right child of " << data << " (-1 for no child): ";
    newNode->right = buildTree();
    return newNode;
}

int main() {
    std::cout << "Enter elements of the first tree (-1 for no child):\n";
    TreeNode* root1 = buildTree();
    
    std::cout << "Enter elements of the second tree (-1 for no child):\n";
    TreeNode* root2 = buildTree();

    if (areIdentical(root1, root2)) {
        std::cout << "The two trees are identical.\n";
    } else {
        std::cout << "The two trees are not identical.\n";
    }

    return 0;
}
