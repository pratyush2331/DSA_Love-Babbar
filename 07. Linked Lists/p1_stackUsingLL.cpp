// GFG : Implemenet Stack using Linked List

#include<iostream>
using namespace std;

class StackNode{
  public:
    int data;
    StackNode* next;

    StackNode(int d) {
        data = d;
        next = NULL;
    }
};

class MyStack{
  private:
    StackNode* top;

  public:
    void push(int d);
    int pop();

    MyStack() {
        top = NULL;
    }
};

int main() {
    int T;
    cin >> T;

    while(T--) {
        MyStack* sq = new MyStack();

        int Q;
        cin >> Q;

        while(Q--) {
            int queryType;
            cin >> queryType;

            if(queryType == 1) {
                int d;
                cin >> d;
                sq->push(d);
            }
            else if(queryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

void MyStack :: push(int d) {

    StackNode* n = new StackNode(d);

    if(top == NULL) {
        top = n;
        return;
    }

    n->next = top;
    top = n;

}

int MyStack :: pop() {

    if(top == NULL) {
        return -1;
    }

    int d = top->data;
    top = top->next;
    return d;

}