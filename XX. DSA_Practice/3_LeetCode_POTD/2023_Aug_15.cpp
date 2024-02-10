// 86. Partition List
// LeetCode : https://leetcode.com/problems/partition-list/

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
    // method-1 : single pass
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* node1 = new ListNode(-1); //dummy LL1
        ListNode* node2 = new ListNode(-1); //dummy LL2
        ListNode* p1 = node1; // pointer to node1
        ListNode* p2 = node2; // pointer to node2

        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) {
                p1->next = temp;
                p1 = p1->next;
            }
            else {
                p2->next = temp;
                p2 = p2->next;
            }

            temp = temp->next;
        }

        p1->next = node2->next;
        p2->next = NULL;

        return node1->next;
    }
    // */



    // method-0 : using 2 arrays/vectors
    /*
    TC : O(n)
    SC : O(n)
    */
    /*
    public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr1, arr2;
        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) arr1.push_back(temp->val);
            else arr2.push_back(temp->val);

            temp = temp->next;
        }

        temp = head;
        for(int i = 0; i < arr1.size(); i++) {
            temp->val = arr1[i];
            temp = temp->next;
        }
        for(int i = 0; i < arr2.size(); i++) {
            temp->val = arr2[i];
            temp = temp->next;
        }

        return head;
    }
    */
};


int main() {
    
    return 0;
}