// 

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

Node* splitCLL(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    if(head->next == head) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != head) {
        fast = fast->next;
        if(fast->next != head) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    Node* head2 = slow->next;
    fast->next = head2;
    slow->next = head;

    return head2;
}

void print(Node* head) {
    if(head == NULL) {
        cout << "NULL" << endl;
        return;
    }

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
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    print(head);

    Node* head2 = splitCLL(head);

    print(head);
    print(head2);
    
    return 0;
}