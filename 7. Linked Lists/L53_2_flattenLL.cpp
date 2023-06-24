// GFG Practice : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<iostream>
using namespace std;

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* merge(Node* left, Node* right) {
    if(left == NULL) {
        return right;
    }
    if(right == NULL) {
        return left;
    }
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->bottom = left;
            temp = temp->bottom;
            left = left->bottom;
        }
        else {
            temp->bottom = right;
            temp = temp->bottom;
            right = right->bottom;
        }
    }
    while(left != NULL) {
        temp->bottom = left;
        temp = temp->bottom;
        left = left->bottom;
    }
    while(right != NULL) {
        temp->bottom = right;
        temp = temp->bottom;
        right = right->bottom;
    }
    
    ans = ans->bottom;
    return ans;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root == NULL) {
       return root;
   }
   
   Node* down = root;
   Node* right = root->next;
   down->next = NULL;
   right = flatten(right);
   
   return merge(down, right);
}

int main() {
    
    return 0;
}