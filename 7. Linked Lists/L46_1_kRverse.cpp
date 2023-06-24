// Coding Ninjas : k-Reverse

#include<iostream>
using namespace std;

// Node - class
class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d) {
    Node* n = new Node(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL) {
        return NULL;
    }

    // step-1 : reverse first k-nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step-2 : recursion dekhlega aage ka
    if(next != NULL) {
        head->next = kReverse(next, k);
    }

    // step-3 : return head of reversed list
    return prev;
}

bool isCircular(Node* head){
    if(head == NULL) {
        return 1;
    }
    
    if(head->next == NULL) {
        return 0;
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
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    print(head);

    // if(isCircular(head)) {
    //     cout << "LL is Circular" << endl;
    // }
    // else {
    //     cout << "LL is Not Circular" << endl;
    // }

    int k;
    cout << "Enter k : ";
    cin >> k;

    // calling kReverse fun
    head = kReverse(head, k);
    
    print(head);

    return 0;
}