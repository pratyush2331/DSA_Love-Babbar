// 2807. Insert Greatest Common Divisors in Linked List
// LeetCode : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

// Topic : linked list, algorithm

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
    int getGCD(int a, int b) {
        while(a && b) {
            if(a < b) b %= a;
            else a %= b;
        }
        
        return max(a, b);
    }
    
    public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // cout << getGCD(6, 10); // --> working
        
        ListNode *curr = head;
        ListNode *next = head->next ? head->next : head;
        while(curr->next) {
            ListNode* newNode = new ListNode(getGCD(curr->val, next->val));
            
            newNode->next = next;
            curr->next = newNode;
            
            curr = curr->next->next;
            // if(next->next)
                next = next->next;
            // else
            //     break;
        }
        
        // ListNode* newNode = new ListNode(getGCD(curr->val, next->val));
        // newNode->next = next;
        // curr->next = newNode;
        
        return head;
    }
};


int main() {
    
    return 0;
}