// 328. Odd Even Linked List
// LeetCode : https://leetcode.com/problems/odd-even-linked-list/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n)
SC : O(1)
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode *h2 = NULL;
        ListNode *p1 = NULL, *p2 = NULL;
        ListNode *temp = head;
        bool flag = 1;
        while(temp) { // TC: O(n)
            if(flag) { // odd
                if(p1 == NULL) {
                    p1 = temp;
                }
                else {
                    p1->next = temp;
                    p1 = p1->next;
                }
            }
            else { // even
                if(p2 == NULL) {
                    h2 = temp;
                    p2 = temp;
                }
                else {
                    p2->next = temp;
                    p2 = p2->next;
                }
            }
            flag = !flag;
            temp = temp->next;
        }
        if(p2) p2->next = NULL;
        p1->next = h2;
        return head;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}