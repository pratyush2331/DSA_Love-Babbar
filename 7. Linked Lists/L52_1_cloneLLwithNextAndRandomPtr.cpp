// GFG Practice : https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include<bits/stdc++.h>
using namespace std;


// Method - 3 (without HashMap)
// TC : O(n), SC : O(1)
class Solution
{
  private:
    void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* temp = new Node(val);
        
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        
        tail->next = temp;
        tail = temp;
    }

  public:
    Node *copyList(Node *head)
    {
        // step-1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            
            temp = temp->next;
        }
        
        // step-2 : cloneNodes add in b/w original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        
        // step-3 : random pointer copy
        temp = head;
        while(temp != NULL) {
            if(temp->next != NULL) {
                if(temp->arb != NULL) {
                    temp->next->arb = temp->arb->next;
                }
            }
            
            temp = temp->next->next;
        }
        
        // step-4 : revert changes done in step-2
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            
            if(originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        
        // step-5 : return ans
        return cloneHead;
    }
};




/*
// Method - 2 (using HashMap)
// TC : O(n), SC : O(n)
class Solution
{
  private:
  void insertAtTail(Node* &head, Node* &tail, int val) {
      Node* temp = new Node(val);
      
      if(head == NULL) {
          head = temp;
          tail = temp;
          return;
      }
      
      tail->next = temp;
      tail = temp;
  }

  public:
    Node *copyList(Node *head)
    {
        // step-1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // step-2 : Create a map
        unordered_map<Node*, Node*> oldToNew;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL) {
            oldToNew[originalNode] = cloneNode;
            
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL) {
            cloneNode->arb = oldToNew[originalNode->arb];
            
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }

};
*/


int main() {
    
    return 0;
}