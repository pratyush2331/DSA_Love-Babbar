// Singly Linked List (SLL) implementation

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

void deleteAtHead(Node* &head) {
    // list is empty
    if(head == NULL) {
        cout << " list is empty ! " << endl;
        return;
    }

    Node* todelete = head;
    head = head->next;

    delete todelete;
}

Node* deleteNode_pos(Node *head,int x)
{
    if(x == 1) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt < x-1) {
        temp = temp->next;
        cnt++;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    
    delete toDelete;
    
    return head;
}

void deleteNode(Node* &head, int d) {
    // when list is empty
    if(head == NULL) {
        cout << " list is empty ! " << endl;
        return;
    }

    // deleting 1st element
    if(head->data == d) {
        deleteAtHead(head);
        return;
    }

    Node* temp = NULL;
    Node* curr = head;
    while(curr != NULL) {
        // element found
        if(curr->data == d) {
            Node* todelete = curr;
            temp->next = curr->next;
            delete todelete;
            return;
        }

        temp = curr;
        curr = curr->next;
    }
    // element not found
    cout << d << " not found ! " << endl;
    return;
}

int main() {
    Node* head = NULL;

    // insertAtHead(head, 1);
    // insertAtHead(head, 2);
    // insertAtHead(head, 3);
    
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    print(head);

    // cout << search(head, 1) << endl;
    // cout << search(head, 2) << endl;
    // cout << search(head, 10) << endl;

    deleteNode(head, 3);
    print(head);

    deleteNode_pos(head, 1);
    print(head);
    
    return 0;
}