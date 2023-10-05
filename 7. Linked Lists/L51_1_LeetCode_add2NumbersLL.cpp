// 2. Add Two Numbers
// LeetCode : https://leetcode.com/problems/add-two-numbers/

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
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);

        ListNode *temp1 = l1, *temp2 = l2, *h = head;
        int sum = 0, carry = 0;
        while(temp1 && temp2) {
            sum = temp1->val + temp2->val + carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            h->next = newNode;
            h = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1) {
            sum = temp1->val + carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            h->next = newNode;
            h = newNode;

            temp1 = temp1->next;
        }

        while(temp2) {
            sum = temp2->val + carry;
            carry = sum/10;
            ListNode* newNode = new ListNode(sum%10);
            h->next = newNode;
            h = newNode;

            temp2 = temp2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(1);
            h->next = newNode;
            h = newNode;
        }

        return head->next;
    }
};


int main() {
    
    return 0;
}