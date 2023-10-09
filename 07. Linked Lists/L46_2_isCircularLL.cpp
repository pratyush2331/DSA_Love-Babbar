// Coding Ninjas : isCircular LL or Not

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val) {
    Node* n = new Node(val);
    
    // when list is empty
    if(head == NULL) {
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);
    // when list is empty
    if(head == NULL) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}


void print(Node* head) {
    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

bool isCircular(Node* head){
    if(head == NULL) {
        return 1;
    }
    
    Node* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        return 0;
    }
    return 1;
}


int main() {
    Node* head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    print(head);

    if(isCircular(head)) {
        cout << "LL is Circular" << endl;
    }
    else {
        cout << "LL is Not Circular" << endl;
    }

    return 0;
}