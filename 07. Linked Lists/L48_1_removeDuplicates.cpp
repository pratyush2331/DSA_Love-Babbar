// Remove Duplicates from a Sorted/Unsorted Linked List

#include<iostream>
#include<map>
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

// for Sorted LL
// TC : O(n), SC : O(1)
Node* uniqueSortedList(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL) {
        if(curr->next != NULL && curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

// for Unsorted LL (using 2 while loops)
// TC : O(n^2), SC : O(1)
Node *removeDuplicates(Node *head) {
    if(head == NULL) {
        return NULL;
    }
    
    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr;
        while(temp->next != NULL) {
            if(curr->data == temp->next->data) {
                Node* next_next = temp->next->next;
                Node* nodeToDelete = temp->next;
                delete nodeToDelete;
                temp->next = next_next;;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    
    return head;
}

// for Unsorted LL (using map)
// TC : O(n), SC : O(n)
Node *removeDuplicatesMap(Node *head) {
    if(head == NULL) {
        return NULL;
    }

    map<int, bool> visited;

    Node* curr = head;
    visited[curr->data] = true;
    
    while(curr->next != NULL) {
        if(visited[curr->next->data] == true) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else {
            visited[curr->next->data] = true;
            curr = curr->next;
        }
    }

    return head;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // head pointed to node1
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 7);

    print(head);

    // uniqueSortedList(head);
    // removeDuplicates(head);
    removeDuplicatesMap(head);

    print(head);

    return 0;
}