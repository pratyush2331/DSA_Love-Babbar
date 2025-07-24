// 142. Linked List Cycle II
// LeetCode : https://leetcode.com/problems/linked-list-cycle-ii/

#include<bits/stdc++.h>
using namespace std;


// Optimal: Floyd's cycle detection
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) { // IMP: after Floyd's cycle detection algo
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


// Brute-Force: map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mp;
        while(head) {
            if(mp[head]) return head;
            mp[head] = 1;
            head = head->next;
        }
        return NULL;
    }
};


int main() {
    
    return 0;
}