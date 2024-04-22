// BST intro

#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root) { // LNR
    // base case
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) { // NLR
    // base case
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) { // NLR
    // base case
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// level order traversal
void levelOrderTraversal(Node* root) {
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}



// 701. Insert into a Binary Search Tree
// LeetCode : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

// using iteration
/*
TC : O(logn) --> traversal in BST
SC : O(1)
*/
Node* insertIntoBST_iteration(Node* root, int val) {
    if(root == NULL) return new Node(val);

    Node* temp = root;
    while(temp) {
        if(temp->val < val) {
            if(temp->right) temp = temp->right;
            else {
                temp->right = new Node(val);
                break;
            }
        }
        else if(temp->val > val) {
            if(temp->left) temp = temp->left;
            else {
                temp->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

// using recursion
/*
TC : O(logn)
SC : O(logn)
*/
Node* insertIntoBST(Node* root, int d) {
    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d < root->data) {
        // left part me insert karna hai
        root->left = insertIntoBST(root->left, d);
    }
    else {
        // right part me insert karna hai
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}



void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minValInBST(Node* root) {
    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}

Node* maxValInBST(Node* root) {
    Node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

// PREDECESSOR & SUCCESSOR
// CodeStudio : https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
// /*
// without using maxValInBst()
Node* inorderPredecessor(Node* root, int key) {
    if(root == NULL)
        return NULL;
    
    Node* ans = NULL;
    Node* temp = root;
    while(temp) {
        if(temp->data < key) {
            ans = temp;
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    return ans;
}

// without using minValInBst()
Node* inorderSuccessor(Node* root, int key) {
    if(root == NULL)
        return NULL;
    
    Node* ans = NULL;
    Node* temp = root;
    while(temp) {
        if(temp->data > key) {
            ans = temp;
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return ans;
}
// */

/*
// using maxValInBst()
Node* inorderPredecessor(Node* root, int key) {
    if(root == NULL)
        return NULL;
    
    Node* ans = NULL;
    Node* temp = root;
    while(temp->data != key) {
        if(temp->data < key) {
            ans = temp;
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }

    // pred
    if(temp->left)
        ans = maxValInBST(temp->left);

    return ans;
}

// using minValInBst()
Node* inorderSuccessor(Node* root, int key) {
    if(root == NULL)
        return NULL;
    
    Node* ans = NULL;
    Node* temp = root;
    while(temp->data != key) {
        if(temp->data > key) {
            ans = temp;
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    // succ
    if(temp->right)
        ans = minValInBST(temp->right);

    return ans;
}
*/

// LeetCode : https://leetcode.com/problems/delete-node-in-a-bst/
// TC : O(h)
Node* deleteFromBST(Node* root, int val) {
    // base case
    if(root == NULL)
        return root;

    if(root->data == val) {
        // 0 child hai
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child hai

        // left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child hai
        if(root->left != NULL && root->right != NULL) {
            int mini = minValInBST(root->right)->data; // right part me se min value nikal rhe hai
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > val) {
        // left part me jao
        root->left = deleteFromBST(root->left, val);
    }
    else {
        // right part me jao
        root->right = deleteFromBST(root->right, val);

    }
    return root;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : " << endl;
    takeInput(root);

    cout << "Printing the BST (levelorder) : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    
    cout << "Printing the inorder : " << endl;
    inorder(root);
    cout << endl;

    // int key;
    // cout << "Enter key : ";
    // cin >> key;

    // // key must present in the BST
    // Node* pre = inorderPredecessor(root, key);
    // if(pre != NULL)
    //     cout << "Predecessor : " << pre->data << endl;
    // else
    //     cout << "No predecessor" << endl;
    
    // Node* suc = inorderSuccessor(root, key);
    // if(suc != NULL)
    //     cout << "Successor : " << suc->data << endl;
    // else
        // cout << "No successor" << endl;

    cout << "Printing the preorder : " << endl;
    preorder(root);
    cout << endl;
    
    cout << "Printing the postorder : " << endl;
    postorder(root);
    cout << endl;

    cout << "Min val in BST : " << minValInBST(root)->data << endl;
    cout << "Max val in BST : " << maxValInBST(root)->data << endl;

    // DELETION
    root = deleteFromBST(root, 50);

    cout << "Printing the BST (levelorder) : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    
    cout << "Printing the inorder : " << endl;
    inorder(root);
    cout << endl;
    
    return 0;
}