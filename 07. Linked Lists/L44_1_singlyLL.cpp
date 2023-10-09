// Singly Linked List (SLL) using class

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

void insertAtHead(Node* &head, Node* &tail, int d) {
    // new node create
    Node* temp = new Node(d);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if(tail == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // insert at 1st Position
    if(position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;

    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if(temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    // deleting 1st node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        // memory free 1st node
        temp->next = NULL;
        delete temp;
        return;
    }

    // deleting any middle node or last node
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 1;
    while(cnt < position) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    
    // checking for last node
    if(curr->next == NULL) {
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(Node* head, int key) {
    Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {

    // created a new node
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;

    // head pointed to node1
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, 10);
    insertAtTail(head, tail, 1);
    // print(head);

    // cout << node1->data << endl;
    // cout << node1->next << endl;


    // print(head);

    // insertAtHead(head, 12);
    insertAtTail(head, tail, 2);
    // print(head);

    // insertAtHead(head, 15);
    insertAtTail(head, tail, 3);
    // print(head);

    insertAtPosition(head, tail, 2, 4);
    print(head);

    // cout << "head: " << head->data << endl;
    // cout << "tail: " << tail->data << endl;

    deleteNode(head, tail, 4);
    print(head);
    
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    cout << search(head, 2) << endl;
    
    return 0;
}