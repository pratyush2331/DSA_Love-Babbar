// Doubly Linked List (DLL) using Class

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int val = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory free for node with data " << val << endl;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* &head) {
    Node* temp = head;

    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);

    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    temp->next = head;
    head->prev = temp;
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
    temp->prev = tail;
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

    // inserting in any middle position
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    // deleting 1st node
    if(position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
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

    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main() {
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << " len = " << getLength(head) << endl;

    insertAtHead(head, tail, 11);
    print(head);
    insertAtHead(head, tail, 12);
    print(head);
    insertAtHead(head, tail, 13);
    print(head);

    insertAtTail(head, tail, 14);
    print(head);

    // cout << " len = " << getLength(head) << endl;

    insertAtPosition(head, tail, 5, 100);
    print(head);
    
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deleteNode(head, tail, 5);
    print(head);

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    
    return 0;
}