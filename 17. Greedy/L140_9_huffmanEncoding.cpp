// Huffman Encoding
// GFG : https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1


/*
TC : O(n.logn)
SC : O(n)
*/

#include<iostream>
using namespace std;


// Node class
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// custom comparator
class cmp {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
    // preorder traversal
    void preorderTraversal(Node* root, string temp, vector<string>& ans) {
        if(root->left == NULL && root->right == NULL) {
            // imp
            ans.push_back(temp);
            return;
        }
        
        // imp
        preorderTraversal(root->left, temp + '0', ans);
        preorderTraversal(root->right, temp + '1', ans);
    }
    
	public:
	vector<string> huffmanCodes(string S,vector<int> f,int N) {
	    // Code here
	    priority_queue<Node*, vector<Node*>, cmp> pq;
	    for(int i = 0; i < N; i++) {
	       // imp
	        Node* temp = new Node(f[i]);
	        pq.push(temp);
	    }
	    
	    while(pq.size() > 1) {
	        Node* left = pq.top();
	        pq.pop();
	        
	        Node* right = pq.top();
	        pq.pop();
	        
	        Node* temp = new Node(left->data + right->data);
	        temp->left = left;
	        temp->right = right;
	        
	        pq.push(temp);
	    }
	    
	    Node* root = pq.top();
	    pq.pop(); // not needed to pop
	    
	   // imp
	    vector<string> ans;
	    string temp = "";
	    preorderTraversal(root, temp, ans);
	    
	    return ans;
	}
};


int main() {
    
    return 0;
}