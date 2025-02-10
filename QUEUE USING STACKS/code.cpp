#include <iostream>
using namespace std;

class Stack {
    int arr[1000]; // Array to store stack elements
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == 999) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

class QueueUsingStacks {
    Stack s1, s2; // Two stacks for implementing the queue

public:
    void enqueue(int x) {
        s1.push(x); // Push element onto the first stack
    }

    void dequeue() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue underflow\n";
            return;
        }

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Remove the front element (top of s2)
        s2.pop();
    }

    int front() {
        if (s1.isEmpty() && s2.isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top(); // Front element is the top of s2
    }

    bool empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.front() << endl; // Output: 10
    queue.dequeue();

    cout << "Front element after dequeue: " << queue.front() << endl; // Output: 20
    queue.dequeue();

    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No
    queue.dequeue();

    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
