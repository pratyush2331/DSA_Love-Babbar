// 

#include<bits/stdc++.h>

using namespace std;

vector<int> preorder(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* top = st.top();
        st.pop();

        ans.push_back(top->val);

        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    

    return 0;
}