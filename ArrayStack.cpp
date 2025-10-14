#include <iostream>
#include "ArrayStack.hpp"
using namespace std;

int main() {
   
    ArrayStack<int> stack(5);

    cout << "Stack created. Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "\nAfter pushing 10, 20, 30:\n" << stack << endl;

    // Peek
    cout << "Peek top element: " << stack.peek() << endl;

    // Pop 
    stack.pop();
    cout << "\nAfter popping one element:\n" << stack << endl;

    // Rotate right
    stack.rotate(Stack<int>::RIGHT);
    cout << "\nAfter rotating RIGHT:\n" << stack << endl;

    // Rotate left
    stack.rotate(Stack<int>::LEFT);
    cout << "\nAfter rotating LEFT:\n" << stack << endl;

    // Copy constructor
    ArrayStack<int> stackCopy(stack);
    cout << "\nCopied stack:\n" << stackCopy << endl;

    // Clear stack
    stack.clear();
    cout << "\nAfter clearing stack. Is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
