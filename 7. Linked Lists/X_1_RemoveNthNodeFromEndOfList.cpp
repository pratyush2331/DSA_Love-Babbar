// 19. Remove Nth Node From End of List
// LeetCode : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/*
TC : O(n)
SC : O(1)
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1 = head, *temp2 = head;
        
        while(n--) {
            temp1 = temp1->next;
        }

        if(!temp1) return head->next;

        while(temp1 && temp1->next) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        ListNode* toDelete = temp2->next;
        temp2->next = temp2->next->next;
        delete toDelete;

        return head;
    }
};


int main() {
    
    return 0;
}