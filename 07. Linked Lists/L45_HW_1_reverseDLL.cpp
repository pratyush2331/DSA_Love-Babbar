// GFG : Reverse DLL

#include <bits/stdc++.h>
using namespace std;
 
/* Node of the doubly linked list */
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};
 
/* Function to reverse a Doubly Linked List */
Node* reverseDLL(Node * head)
{
    // ITERATIVE APPROACH
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    Node* curr = head;
    Node* temp = NULL; // will point to prev of curr
    
    while(curr != NULL) {
        temp = curr->prev;
        swap(curr->next, curr->prev);
        curr = curr->prev;
    }
    return temp->prev;
}

void push(Node* &head, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* since we are adding at the beginning,
    prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list of the new node */
    new_node->next = head;
 
    /* change prev of head node to new node */
    if ((head) != NULL)
        (head)->prev = new_node;
 
    /* move the head to point to the new node */
    (head) = new_node;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    Node* head = NULL;
 
    /* Let us create a sorted linked list to test the
    functions Created linked list will be 10->8->4->2 */
    push(head, 2);
    push(head, 4);
    push(head, 8);
    push(head, 10);
 
    cout << "Original Linked list" << endl;
    printList(head);
 
    // Function call
    head = reverseDLL(head);
 
    cout << "\nReversed Linked list" << endl;
    printList(head);
 
    return 0;
}