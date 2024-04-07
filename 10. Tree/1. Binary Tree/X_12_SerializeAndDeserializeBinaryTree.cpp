// 297. Serialize and Deserialize Binary Tree
// LeetCode : https://leetcode.com/problems/serialize-and-deserialize-binary-tree

#include<bits/stdc++.h>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// method-1 : using preorder
/*
TC : O(n)
SC : O(n)
*/
class Codec {
    // serializeUtil
    void serializeUtil(TreeNode* root, string& ans) {
        if(root == NULL) {
            ans.append("#,");
            return;
        }
        ans.append(to_string(root->val) + ',');
        serializeUtil(root->left, ans);
        serializeUtil(root->right, ans);
    }

    // deserializeUtil
    TreeNode* deserializeUtil(stringstream& s) {
        string str;
        getline(s, str, ',');
        if(str == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deserializeUtil(s);
        root->right = deserializeUtil(s);
        return root;
    }

public:
    // to make i/p o/p fast
    Codec() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        serializeUtil(root, ans);
        // cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return deserializeUtil(s);
    }
};



// method-0 : using Level Order Traversal
/*
TC : O(n)
SC : O(n)
*/
class Codec {
public:
    Codec() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(front->val) + ',');
                q.push(front->left);
                q.push(front->right);
            }
        }
        // cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            // left part
            getline(s, str, ',');
            if(str == "#") {
                front->left = NULL;
            }
            else {
                front->left = new TreeNode(stoi(str));
                q.push(front->left);
            }

            // right part
            getline(s, str, ',');
            if(str == "#") {
                front->right = NULL;
            }
            else {
                front->right = new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


int main() {

    return 0;
}