// 234. Palindrome Linked List
// LeetCode : https://leetcode.com/problems/palindrome-linked-list/

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

// Method-1 : Optimal Solution
// /*
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // cout << slow->val << endl;
        slow = reverse(slow);

        fast = head;
        while(slow && fast) {
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};
// */



// Method-0 : Brute Force
/*
class Solution {
    bool checkPalindrome(string& str) {
        int s = 0, e = str.length() - 1;
        while(s < e) {
            if(str[s++] != str[e--]) return false;
        }
        return true;
    }

    public:
    bool isPalindrome(ListNode* head) {
        string str = "";

        ListNode* temp = head;
        while(temp) {
            str += to_string(temp->val);
            temp = temp->next;
        }

        return checkPalindrome(str);
    }
};
*/


int main() {
    
    return 0;
}