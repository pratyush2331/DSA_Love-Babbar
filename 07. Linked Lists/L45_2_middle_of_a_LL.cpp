// Middle of Linked List

#include<bits//stdc++.h>
using namespace std;

class Solution {
  public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return slow;
    }
};

int main() {
    
    return 0;
}