#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete(temp);
        return top->data;
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool is_empty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    s.push(5);
    cout<<"Pushed 5"<<endl;
    s.push(10);
    cout<<"Pushed 10"<<endl;
    s.push(15);
    cout<<"Pushed 15"<<endl;
    cout <<"Top Element: "<<s.peek()<<endl;
    cout <<"Top Element after pop: "<<s.pop()<<endl;
    cout <<"Top Element after pop: "<<s.pop()<<endl;
}
