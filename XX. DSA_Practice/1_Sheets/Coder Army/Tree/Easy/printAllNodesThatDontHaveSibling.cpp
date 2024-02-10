// Print all nodes that don't have sibling
// GFG : https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

#include<bits/stdc++.h>

using namespace std;


// remove duplicates if any in ans array
void remove_duplicates(vector<int>& ans) {
    int i = 0;
    while(i < ans.size()) {
        if(ans[i] == ans[i+1])
            ans.erase(ans.begin()+i);
        i++;
    }
}

void solve(Node* node, vector<int>& ans) {
    if(node == NULL)
        return;
    
    // processing...
    if(node->left != NULL && node->right == NULL) {
        ans.push_back(node->left->data);
    }
    if(node->left == NULL && node->right != NULL) {
        ans.push_back(node->right->data);
    }
    
    solve(node->left, ans);
    solve(node->right, ans);
}

vector<int> noSibling(Node* node) {
    vector<int> ans;
    solve(node, ans);
    
    if(ans.size() == 0) {
        return {-1};
    }
    else {
        sort(ans.begin(), ans.end());
        remove_duplicates(ans);
        return ans;
    }
}


int main() {
    

    return 0;
}