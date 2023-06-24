// Circular Linked List (CLL) implementation

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

void deleteAtHead(Node* &head) {
    // when list is empty
    if(head == NULL) {
        cout << " list is empty ! " << endl;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    Node* todelete = temp->next;
    temp->next = head->next;
    head = temp->next;

    delete todelete;
}

void deleteNode(Node* &head, int pos) {

    if(head == NULL) {
        cout << " list is empty ! " << endl;
        return;
    }

    if(pos == 1) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count != pos-1) {
        temp = temp->next;
        count++;
    }

    Node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void print(Node* head) {
    Node* temp = head;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    print(head);
    insertAtTail(head, 5);
    print(head);

    deleteNode(head, 5);
    print(head);
    deleteNode(head, 1);
    print(head);

    return 0;
}