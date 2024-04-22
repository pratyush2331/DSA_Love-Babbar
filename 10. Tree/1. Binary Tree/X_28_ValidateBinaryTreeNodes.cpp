// 1361. Validate Binary Tree Nodes
// LeetCode : https://leetcode.com/problems/validate-binary-tree-nodes/description/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int dfsTraversal(int root, vector<int>& leftChild, vector<int>& rightChild) {
        if(root == -1) return 0;
        int left = (root == -1) ? 0 : dfsTraversal(leftChild[root], leftChild, rightChild);
        int right = (root == -1) ? 0 : dfsTraversal(rightChild[root], leftChild, rightChild);
        return 1 + left + right;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> childToParent;
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(childToParent.find(leftChild[i]) == childToParent.end()) childToParent[leftChild[i]] = i; // left ka parent -> 'i'
                else return 0;
            }
            if(rightChild[i] != -1) {
                if(childToParent.find(rightChild[i]) == childToParent.end()) childToParent[rightChild[i]] = i; // right ka prent -> 'i'
                else return 0;
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(childToParent.find(i) == childToParent.end()) { // root mil gaya
                if(root != -1) { // pehle v ek root mila tha
                    return 0;
                }
                root = i;
            }
        }
        if(root == -1) { // koi root nahi hai
            return 0;
        }

        return dfsTraversal(root, leftChild, rightChild) == n; // saare nodes present hai --> 1 connected tree hai
    }
};


int main() {

    return 0;
}