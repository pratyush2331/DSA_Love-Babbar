// 2816. Double a Number Represented as a Linked List
// LeetCode : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/

#include<iostream>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *temp = NULL;
        while(curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    public:
    ListNode* doubleIt(ListNode* head) {
        // reverse
        head = reverse(head);

        // do carry and sum thing
        int carry = 0;
        ListNode* temp = head, *prev = NULL;
        while(temp) {
            int sum = carry + 2*temp->val;
            temp->val = sum%10;
            carry = sum/10;

            prev = temp;
            temp = temp->next;
        }
        if(carry) {
            prev->next = new ListNode(1);
        }


        // again reverse
        head = reverse(head);

        return head;
    }
};


int main() {
    
    return 0;
}