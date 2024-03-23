// ZigZag Tree Traversal
// GFG : https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

#include<iostream>
using namespace std;

/*Structure of the node of the binary tree is as

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

*/

class Solution {
    public:
    vector<int> zigZagTraversal(Node* root) // BFS - Breadth First Search
    {
    	vector<int> ans;
    	
    	if(root == NULL) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	bool leftToRight = true; // flag
    	while(!q.empty()) {
    	    int size = q.size();
    	    vector<int> temp(size);
    	    for(int i = 0; i < size; i++) {
    	        Node* frontNode = q.front();
    	        q.pop();
    	        int index = leftToRight ? i : size-i-1;
    	        temp[index] = frontNode->data;
    	        if(frontNode->left) q.push(frontNode->left);
    	        if(frontNode->right) q.push(frontNode->right);
    	    }
    	    ans.push_back(temp);
    	    leftToRight = !leftToRight; // toggling the flag
    	}
    	
    	return ans;
    }
};

int main() {
    
    return 0;
}