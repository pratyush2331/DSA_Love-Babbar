// Implementaion of stack using Linked List (Dynamically, means, no size limit)

#include<iostream>
using namespace std;


class StackNode {
  public:
    int data;
    StackNode* next;

    StackNode(int a) { // Constructor
        this->data = a;
        this->next = NULL;
    }
};

StackNode* top = NULL; //top of stack initialized to NULL
int size = 0; // size of stack initialized to 0


bool isEmpty() {
    if(top == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void push(int x) {
    StackNode* node = new StackNode(x);
    node->next = top;
    top = node;
    cout << x << " is pushed" << endl;
    size++;
}

int pop() {
    if(isEmpty()) {
        cout << " Stack is empty" << endl;
        return INT_MIN;
    }
    else {
        size--;
        int temp = top->data;
        StackNode* tempNode = top;
        top = top->next;
        delete tempNode;
        return temp;
    }
}

int peek() {
    if(isEmpty()) {
        cout << " stack is empty" << endl;
        return INT_MIN;
    }
    else {
        return top->data;
    }
}



int main(){
    
    //menu for operations
    cout<<"press 1 for push\n";
    cout<<"press 2 for pop()\n";
    cout<<"press 3 for top()\n";
    cout<<"press 4 for size()\n";
    cout<<"press 0 for exit\n";
    
    
    int choice;
    cout<<"press your choice\n";
    cin>>choice;
    
    while(choice){
        if(choice==1){
            int data;
            cout<<"Enter element\n";
            cin>>data;
            push(data);
        }
        
        else if(choice==2){
            int item=pop();
            if(item==INT_MIN){}
            else
                cout<<"Popped element: "<<item<<endl;
        }

        else if(choice==3){
            int item=peek();
            if(item==INT_MIN){}
            else
                cout<<"Top element: "<<item<<endl;
        }
        
        else if(choice==4){
            cout<<"Size is: "<<size<<endl;
        }
        
        else
            cout<<"Invalid number, try again!\n";

        cout<<"press your choice\n";
        cin>>choice;
    }
    
    cout<<"Exiting...\n";
    return 0;
}
