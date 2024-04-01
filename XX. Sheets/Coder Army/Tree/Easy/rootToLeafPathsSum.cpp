// Root to leaf paths sum
// GFG : https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

// #include<iostream>
#include<bits/stdc++.h>

using namespace std;


void solve(Node* root, string str, long long& ans) {
    if(root == NULL)
        return;
    
    str = str + to_string(root->data);
    
    if(root->left == NULL && root->right == NULL) {
        ans += stoll(str);
    }
    
    solve(root->left, str, ans);
    solve(root->right, str, ans);
}

long long treePathsSum(Node *root)
{
    long long ans = 0;
    string str = "";
    solve(root, str, ans);
    return ans;
}


int main() {
    

    return 0;
}