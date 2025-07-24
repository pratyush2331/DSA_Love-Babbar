// Detect Loop in a LL
// LeetCode : https://leetcode.com/problems/linked-list-cycle/

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

// TC : O(n), SC : O(n)
Node* detectLoop(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    map<Node*, bool> visited;

    Node* temp = head;
    while(temp != NULL) {
        
        // cycle is present
        if(visited[temp] == true) {
            // cout << "present at " << temp->data << endl;
            return temp;
        }
        
        visited[temp] = true;
        temp = temp->next;
    }
    return NULL;
}

// TC : O(n), SC : O(1)
Node* floydDetectLoop(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(slow != NULL && fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if(fast == slow) {
            // cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* PoI = floydDetectLoop(head);
    if(PoI == NULL) {
        return NULL;
    }

    Node* slow = head;
    while(slow != PoI) {
        slow = slow->next;
        PoI = PoI->next;
    }

    return slow;
}

void removeLoop(Node* head) {
    if(head == NULL) {
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
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

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    tail->next = head->next;

    // print(head);

    // using HashMap
    // /*
    if(detectLoop(head) != NULL) {
        cout << "Loop is present at " << detectLoop(head)->data << endl;
    }
    else {
        cout << "Loop is not present !" << endl;
    }
    // */

    // using Floyd's Cycle Detection Algo
    if(floydDetectLoop(head) != NULL) {
        cout << "Loop is present at " << getStartingNode(head)->data << endl;
    }
    else {
        cout << "Loop is not present !" << endl;
    }

    // removing Loop
    removeLoop(head);

    print(head);

    return 0;
}