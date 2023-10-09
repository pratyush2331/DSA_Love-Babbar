// Circular Linked List implementation

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    Node* temp = new Node(d);

    // if list is empty
    if(tail == NULL) {
        tail = temp;
        temp->next = temp;
        return;
    }

    // when list is not empty
    Node* curr = tail;
    while(curr->data != element && curr->next != tail) {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
}

void print(Node* &tail) {
    // when tail is empty
    if(tail == NULL) {
        cout << " List is empty! " << endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);

    cout << endl;
}

void deleteNode(Node* &tail, int d) {
    // empty list
    if(tail == NULL) {
        cout << " List is empty, please check again! " << endl;
        return;
    }

    Node* prev = NULL;
    Node* curr = tail;

    while(curr->next != tail) {
        curr = curr->next;
    }

    // if list has single element

}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    // cout << tail->data << endl;
    print(tail);

    // 8 is not present
    // insertNode(tail, 8, 5);
    // print(tail);

    insertNode(tail, 3, 5);
    print(tail);
    
    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);
    
    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);
    
    insertNode(tail, 3, 4);
    print(tail);

    return 0;
}