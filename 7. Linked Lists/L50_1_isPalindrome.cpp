// GFG Practice : https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include<iostream>
using namespace std;

// Method - 2
// TC : O(n), SC : O(1)
class Solution{
  private:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head->next == NULL) {
            return true;
        }
        
        // Step-1 : find middle
        Node* middle = getMid(head);
        
        // Step-2 : reverse list after middle
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        // Step-3 : compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;
        
        while(head2 != NULL) {
            if(head1->data != head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};




// Method - 1
// TC : O(n), SC : O(n)
/*
#include<vector>

class Solution{
  private:
    bool checkPalindrome(vector<int> arr) {
        int e = arr.size() - 1;
        int s = 0;
        while(s <= e) {
            if(arr[s] != arr[e]) {
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }

  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        
        Node* temp = head;
        while(temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        
        return checkPalindrome(arr);
    }
};
*/

int main() {
    
    return 0;
}