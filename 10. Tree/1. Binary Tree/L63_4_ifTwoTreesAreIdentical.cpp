// Determine if Two Trees are Identical
// GFG : https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// LeetCode : https://leetcode.com/problems/same-tree/

#include<iostream>
using namespace std;

// TC : O(n)
bool isIdentical(Node *r1, Node *r2) {
    if(r1 == NULL && r2 == NULL) return 1;
    if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)) return 0;
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool sameVal = r1->data == r2->data;
    
    if(left && right && sameVal) {
        return 1;
    }
    else {
        return false;
    }
}

int main() {
    
    return 0;
}