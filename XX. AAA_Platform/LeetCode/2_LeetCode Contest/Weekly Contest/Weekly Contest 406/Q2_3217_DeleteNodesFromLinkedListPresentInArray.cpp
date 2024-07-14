// 3217. Delete Nodes From Linked List Present in Array
// LeetCode : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array

#include<bits/stdc++.h>
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool> mp; // {ele, is_present}
        for(auto ele : nums) {
            mp[ele] = 1;
        }
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* ansNode = dummy;
        while(temp) {
            // cout << temp->val << " ";
            if(mp.find(temp->val) == mp.end()) { // not present
                // cout << temp->val << " ";
                ansNode->next = new ListNode(temp->val);
                ansNode = ansNode->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};


int main() {
    
    return 0;
}