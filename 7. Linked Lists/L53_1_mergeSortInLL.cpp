// 

#include<iostream>
using namespace std;

/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* merge(node* left, node* right) {
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }
    while(left != NULL) {
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while(right != NULL) {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }
    
    ans = ans->next;
    return ans;
}

node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeSort(node *head) {
    // base case
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    // break linked list into 2 halves
    node* mid = findMid(head);
    
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;
    
    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    // merge both left and right halves
    node* result = merge(left, right);
    
    return result;
}


int main() {
    
    return 0;
}