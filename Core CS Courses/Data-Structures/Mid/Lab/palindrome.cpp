#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Queue {
private:
    char arr[MAX_SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(char x) {
        if (isFull()) {
            cout << "Error: Queue is full." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    char getFront() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return '\0';
        }

        return arr[front];
    }

    char getRear() {
        if (isEmpty()) {
            cout << "Error: Queue is empty." << endl;
            return '\0';
        }

        return arr[rear];
    }
};

bool isPalindrome(string str) {
    Queue q;
    int n = str.length();


    for (int i = n - 1; i >= 0; i--) {
        q.enqueue(str[i]);
    }


    for (int i = 0; i < n; i++) {
        if (q.getFront() != str[i]) {
            return false;
        }
        q.dequeue();
    }

    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
