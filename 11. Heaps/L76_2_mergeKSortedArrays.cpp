// Merge k Sorted Arrays
// GFG : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include<iostream>
using namespace std;

// OPTIMAL APPROACH
/*
TC : O(n*k logk)
SC : O(k)
*/
class node {
    public:
    int data;
    int i;
    int j;
    
    node(int data, int row, int col) {
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

class Solution {
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        //code here
        
        // min heap
        priority_queue<node*, vector<node*>, compare> pq;
        
        // step-1: saare 'K' arrays ke first element ko insert kro
        for(int i = 0; i < K; i++) { // TC: O(k.logk), SC: O(k)
            node* temp = new node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        // step-2: Insert next smaller element in min heap and also store it in ans array and pop from min heap
        vector<int> ans; // SC: O(n*k)
        while(pq.size() > 0) { // TC: O(n*k logk) SC: O(n*k)
            node* temp = pq.top();
            pq.pop();
            
            ans.push_back(temp->data);
            
            int i = temp-> i;
            int j = temp-> j;
            
            if(j+1 < arr[i].size()) {
                node* next = new node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
        }
        
        // step-3: return ans array
        return ans;
    }
};




// BRUTE FORCE
/*
TC : O((n*k).log(n*k))
SC : O(n*k)
*/
/*
class Solution {
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        //code here
        
        // create ans array and store all elements from all k arrays
        vector<int> ans; // SC: O(n*k)
        for(int i = 0; i < K; i++) { // TC: O(n*k)
            for(int j = 0; j < arr[i].size(); j++) {
                ans.push_back(arr[i][j]);
            }
        }
        
        // step-2: sort ans array
        sort(ans.begin(), ans.end()); // TC: O((n*k).log(n*k))
        
        // step-3: return ans array
        return ans;
    }
};
*/

int main() {
    
    return 0;
}