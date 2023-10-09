// Reverse List In K Groups
// LeetCode : https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *curr = dummy, *next = dummy, *prev = dummy;
        
        int len = 0;
        while(curr->next) {
            len++;
            curr = curr->next;
        }
        
        while(len >= k) {
            curr = prev->next;
            next = curr->next;
            for(int i = 1; i < k; i++) {
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev = curr;
            len -= k;
        }

        return dummy->next;
    }
};


int main() {
    
    return 0;
}