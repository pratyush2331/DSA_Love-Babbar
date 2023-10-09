// 203. Remove Linked List Elements
// LeetCode : https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while(curr->next) {
            if(curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};


int main() {
    
    return 0;
}