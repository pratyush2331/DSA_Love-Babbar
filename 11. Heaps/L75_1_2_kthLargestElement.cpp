// 215. Kth Largest Element in an Array
// LeetCode : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// TC : O(n logk), SC : O(k)

#include<iostream>
using namespace std;

class Solution {
    public:
    // using min heap
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = nums.size();
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        for(int i = k; i < n; i++) {
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

int main() {
    
    return 0;
}