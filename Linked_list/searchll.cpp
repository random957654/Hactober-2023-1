#include <iostream>

// Define a simple Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to search for a value in the linked list
bool search(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    Node* current = head;
    for (int i = 2; i <= 5; i++) {
        current->next = new Node(i);
        current = current->next;
    }

    // Search for a value in the linked list
    int target = 3;
    if (search(head, target)) {
        std::cout << "Value " << target << " found in the linked list." << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the linked list." << std::endl;
    }

    // Clean up the allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
