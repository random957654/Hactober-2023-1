#include <iostream>
#include <stack>

int main() {
    std::stack<int> myStack; // Create an integer stack

    // Push elements onto the stack
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Get the top element (without removing it)
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Pop elements from the stack
    while (!myStack.empty()) {
        std::cout << "Popped: " << myStack.top() << std::endl;
        myStack.pop();
    }

    // Check if the stack is empty again
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}
