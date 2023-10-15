#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a node at the end of the linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete the first occurrence of a node with a given value
void deleteNode(Node*& head, int val) {
    if (!head) return;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

// Function to search for a node with a given value
bool search(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to print the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to delete the entire linked list to free memory
void deleteLinkedList(Node*& head) {
    Node* current = head;
    Node* next;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    // Insert nodes
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    std::cout << "Linked List: ";
    print(head);

    // Search for a node
    int searchValue = 3;
    std::cout << "Search for " << searchValue << ": " << (search(head, searchValue) ? "Found" : "Not found") << std::endl;

    // Delete a node
    int deleteValue = 2;
    deleteNode(head, deleteValue);
    std::cout << "Linked List after deleting " << deleteValue << ": ";
    print(head);

    // Delete the entire linked list
    deleteLinkedList(head);

    return 0;
}
