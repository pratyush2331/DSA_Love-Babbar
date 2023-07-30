// Implementation of stack using array

#include<iostream>
using namespace std;

class Stack {
    // properties:
    int* arr;
    int top;
    int size;

    // behaviour
  public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << " Stack Overflow ! " << endl;
        }
    }

    void pop() {
        if(top > -1) {
            top--;
        }
        else {
            cout << " Stack Underflow ! " << endl;
        }
    }

    int peek() {
        if(top > -1) {
            return arr[top];
        }
        else {
            cout << " Stack is empty ! " << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};



int main() {

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    cout << " top element : " << st.peek() << endl;

    st.pop();

    cout << " top element : " << st.peek() << endl;

    st.pop();

    cout << " top element : " << st.peek() << endl;

    st.pop();

    cout << " top element : " << st.peek() << endl;

    cout << " empty or not : " << st.isEmpty() << endl;

    return 0;
}
