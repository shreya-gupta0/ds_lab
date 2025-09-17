#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(int x) {
    if (isFull())
        cout << "Stack Overflow\n";
    else
        stackArr[++top] = x;
}

void pop() {
    if (isEmpty())
        cout << "Stack Underflow\n";
    else
        cout << "Popped: " << stackArr[top--] << "\n";
}

void peek() {
    if (isEmpty())
        cout << "Stack is Empty\n";
    else
        cout << "Top Element: " << stackArr[top] << "\n";
}

void display() {
    if (isEmpty()) {
        cout << "Stack is Empty\n";
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; --i) cout << stackArr[i] << " ";
    cout << "\n";
}

int main() {
    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Check Empty\n4. Check Full\n";
        cout << "5. Display\n6. Peek\n0. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) break;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2: pop(); break;
            case 3: cout << (isEmpty() ? "Stack is Empty\n" : "Stack is NOT Empty\n"); break;
            case 4: cout << (isFull()  ? "Stack is Full\n"  : "Stack is NOT Full\n");  break;
            case 5: display(); break;
            case 6: peek(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
