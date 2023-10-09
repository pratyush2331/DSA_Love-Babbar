// GFG Practice : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

#include<iostream>
using namespace std;

/* node for linked list

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
  private:
    struct Node* reverse(struct Node* head) {
        struct Node* curr = head;
        struct Node* prev = NULL;
        struct Node* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        struct Node* temp = new Node(val);
        
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        
        tail->next = temp;
        tail = temp;
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        struct Node* ansHead = NULL;
        struct Node* ansTail = NULL;
        while(first != NULL || second != NULL || carry != 0) {
            int val1 = 0;
            if(first != NULL) {
                val1 = first->data;
            }
            
            int val2 = 0;
            if(second != NULL) {
                val2 = second->data;
            }
            
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            if(first != NULL) {
                first = first->next;
            }
            
            if(second != NULL) {
                second = second->next;
            }
        }
        return ansHead;
    }
  
  public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // step-1 : reverse i/p LL
        first = reverse(first);
        second = reverse(second);
        
        // step-2 : add LL
        struct Node* ans = add(first, second);
        
        // step-3 : reverse ans
        ans = reverse(ans);
        
        return ans;
    }
};

int main() {
    
    return 0;
}