// 117. Populating Next Right Pointers in Each Node II
// LeetCode : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

#include<bits/stdc++.h>
using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Logic : Level Order Traversal
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q; // SC:O(n)
        q.push(root);
        while(!q.empty()) {
            int x = q.size();
            Node* prevNode = NULL;
            while(x--) { // TC:O(n)
                Node* front = q.front();
                q.pop();
                if(front->left) {
                    if(prevNode) prevNode->next = front->left;
                    prevNode = front->left;
                    q.push(front->left);
                }
                if(front->right) {
                    if(prevNode) prevNode->next = front->right;
                    prevNode = front->right;
                    q.push(front->right);
                }
            }
        }
        return root;
    }
};


int main() {

    return 0;
}