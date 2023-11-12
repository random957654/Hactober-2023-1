#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;

    int height(Node* node);
    int getBalance(Node* node);
    Node* createNode(int key);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, int key);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);

public:
    AVLTree();
    void insert(int key);
    void deleteNode(int key);
    void inorderTraversal();
};

AVLTree::AVLTree() {
    root = nullptr;
}

int AVLTree::height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

int AVLTree::getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

Node* AVLTree::createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::insert(Node* node, int key) {
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    if (balance > 1) {
        if (key < node->left->key) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balance < -1) {
        if (key > node->right->key) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVLTree::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0) {
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balance < -1) {
        if (getBalance(root->right) <= 0) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::deleteNode(int key) {
    root = deleteNode(root, key);
}

void AVLTree::inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    AVLTree avl;
    int choice, key;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                avl.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                avl.deleteNode(key);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                avl.inorderTraversal(avl.getRoot());
                cout << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
