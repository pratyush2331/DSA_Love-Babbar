// 632. Smallest Range Covering Elements from K Lists
// LeetCode : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

/*
TC : O((n*k).logk)
SC : O(k)
*/

#include<iostream>
using namespace std;

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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        int mini = INT_MAX, maxi = INT_MIN;

        // min heap
        priority_queue<node*, vector<node*>, compare> pq; // SC: O(k)

        // step-1: Inserting first element of all k lists in min heap and tracking mini.maxi value
        for(int i = 0; i < k; i++) { // TC: O(k.logk)
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(new node(element, i, 0));
        }

        // step-2: get mini and maxi
        int start = mini, end = maxi;

        // step-3: processing ranges
        while(!pq.empty()) { // TC: O((n*k).log(k))
            // fetched mini
            node* temp = pq.top();
            pq.pop();

            mini = temp->data;

            // range or answer updation
            if(maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // next element exists
            if(temp->j + 1 < nums[temp->i].size()) {
                maxi = max(maxi, nums[temp->i][temp->j + 1]);
                pq.push(new node(nums[temp->i][temp->j + 1], temp->i, temp->j + 1));
            }
            else { // next element does not exist
                break;
            }
        }

        // return range
        return {start, end};
    }
};

int main() {
    
    return 0;
}