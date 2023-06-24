// LeetCode-206 : Reverse Linked List

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // METHOD-3 : Recursive Approach
    ListNode* reverse(ListNode* head) {
        if(!head || !(head->next)) {
            return head;
        }
        ListNode* chotaHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return chotaHead;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }

    // METHOD-2 : using Recursive Approach
    /*
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev) {
        if(!curr) {
            head = prev;
            return;
        }
        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        reverse(head, curr, prev);
        return head;
    }
    */

    // METHOD-1 : using Iterative Approach
    /*
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            // update kr diye curr ko aur prev ko
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    */
};

void insertAtHead(ListNode* &head, int d) {
    // new node create
    ListNode* temp = new ListNode(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(ListNode* &head, int d) {
    ListNode* n = new ListNode(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    ListNode* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution obj;
    ListNode* head = NULL;
    int n;
    cout << "Enter Size : ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head,val);
    }
    print(head);
    head = obj.reverseList(head);
    print(head);
    return 0;
}