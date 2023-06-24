// Morris Trvaersal
// TC : O(n), SC : O(1)

#include<iostream>
using namespace std;

// for Inorder traversal
void morrisTraversal(Node* root) {
    if(root == NULL)
        return;
    
    Node *current, *predecessor;
    current = root;

    while(current != NULL) {
        if(current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            // get predecessor
            predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            // temp link creation
            if(predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            }
            // temp link removal
            else {
                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    
    return 0;
}