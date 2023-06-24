// 23. Merge k Sorted Lists
// LeetCode : https://leetcode.com/problems/merge-k-sorted-lists/

// 2 approaches



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


// OPTIMAL APPROACH
/*
TC : O((n*k).logk)
SC : O(k)
*/
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; // SC: O(k)

        int k = lists.size();

        if(k == 0)
            return NULL;

        // step-1: Insert first elements from all 'k' LLs in min heap
        for(int i = 0; i < k; i++) { // TC: O(k.logk)
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        // step-2: Insert next smaller elements in min heap
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(pq.size() > 0) { // TC: O((n*k).logk)
            ListNode* top = pq.top();
            pq.pop();

            if(top->next != NULL) {
                pq.push(top->next);
            }

            if(head == NULL) { // answer LL is empty
                head = top;
                tail = top;
                // if(tail->next != NULL) {
                //     pq.push(tail->next);
                // }
            }
            else { // insert at LL
                tail->next = top;
                tail = top;
                // if(tail->next != NULL) {
                //     pq.push(tail->next);
                // }
            }
        }

        // step-3: return head of modified LL
        return head;
    }
};



// BRUTE FORCE
/*
TC : O((n*k).log(n*k))
SC : O(n*k)
*/
/*
class Solution {
    void storeInArray(ListNode* head, vector<int>& ans) {
        ListNode* temp = head;
        while (temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
    }

    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // step-1: store all elements of LL in ans array
        vector<int> ans;
        int cnt = 0;
        for (ListNode* head : lists) {
            if(head == NULL) cnt++; // if all heads are pointing to NULL
            storeInArray(head, ans);
        }

        if(cnt == lists.size()) return NULL;

        // step-2: sort all elements in the ans array
        sort(ans.begin(), ans.end());

        // Step 3: Create a new linked list from sorted ans array
        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;
        for (int i = 1; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        // step-4: return ans
        return newHead;
    }
};
*/

int main() {
    
    return 0;
}