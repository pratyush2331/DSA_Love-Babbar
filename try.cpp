// 

#include<bits/stdc++.h>

using namespace std;


vector<int> inorderIterative(node* root) {
    vector<int> ans;

    stack<node*> st;
    node* curr = root;
    while(true) {
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            if(st.empty()) break;
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }

    return ans;
}


int main() {
    

    return 0;
}