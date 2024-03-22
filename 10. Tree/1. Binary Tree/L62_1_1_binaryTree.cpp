// Binary Tree Creation
/*
Different Traversal Techniques:-
1. Level Order Traversal - BFS
2. In Order Traversal - DFS
3. Pre Order Traversal - DFS
4. Post Order Traversal - DFS
*/

#include<iostream>
#include<queue>
using namespace std;

class node {
  public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data : ";
    int data;
    cin >> data;
    
    // base case
    if(data == -1) { // -1 ko NULL man rha hun
        return NULL;
    }

    root = new node(data);

    cout << "Enter data to insert in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to insert in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}




void levelOrderTraversal(node* root) { // BFS - Breadth First Search
    if(root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        int x = q.size();
        
        while(x--) {
            node* frontNode = q.front();
            q.pop();

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }

            cout << frontNode->data << " ";
        }
        cout << endl;
    }
}

// HOMEWORK : reverse level order traversal
/*
void reverseLevelOrderTraversal(node* root) {
    
}
*/




/*
TC : O(n)
SC : O(height)
*/
void inorder(node* root) { // LNR
    // base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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




void preorder(node* root) { // NLR
    // base case
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/*
TC : O(n)
SC : O(height)
*/
vector<int> preorderIterative(node* root) {
    vector<int> ans;

    if(root == NULL) return ans;

    stack<node*> st;
    st.push(root);
    while(!st.empty()) {
        node* top = st.top();
        st.pop();
        ans.push_back(top->data);
        if(top->right) st.push(top->right);
        if(top->left) st.push(top->left);
    }

    return ans;
}




void postorder(node* root) { // NLR
    // base case
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// method-2 : using 1 stack (Iterative Approach)
/*
TC : O(2n)
SC : O(n)
*/
vector<int> postorderIterative(node* root) {
    vector<int> ans;

    if(root == NULL) return ans;

    stack<TreeNode*> st; // SC:O(n)
    TreeNode* curr = root;
    while(curr || !st.empty()) { // TC:O(2n)
        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            TreeNode* temp = st.top()->right;
            if(temp == NULL) {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else {
                curr = temp;
            }
        }
    }

    return ans;
}

// method-1 : using 2 stacks (Iterative Approach)
/*
TC : O(2n)
SC : O(2n)
*/
/*
vector<int> postorderIterative(node* root) {
    vector<int> ans;

    if(root == NULL) return ans;

    stack<TreeNode*> st1, st2; // SC:O(2n)
    st1.push(root);
    while(!st1.empty()) { // TC:O(n)
        TreeNode* top = st1.top();
        st1.pop();
        st2.push(top);
        if(top->left) st1.push(top->left);
        if(top->right) st1.push(top->right);
    }
    while(!st2.empty()) { // TC:O(n)
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}
*/




void buildFromLevelOrder(node* &root) {
    int data;
    cout << "Enter data for root node : ";
    cin >> data;

    if(data == -1) return;

    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left node of " << temp -> data << " : ";
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cout << "Enter data for right node of " << temp -> data << " : ";
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

int main() {
    node* root = NULL;

    // creating a Tree (Levelorder)
    buildFromLevelOrder(root);

    // /*
    // creating a Tree (Preorder)
    // root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // */

    cout << "Level order traversal : " << endl;
    levelOrderTraversal(root);

    cout << "Inorder traversal : ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder traversal : ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder traversal : ";
    postorder(root);
    cout << endl;

    return 0;
}