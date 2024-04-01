// 215. Kth Largest Element in an Array
// LeetCode : https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<iostream>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // k-size tak ka element lele rha hun
        for(int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++) {
            // agar nums[i] bda hai to minHeap me dalo
            if(nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        return minHeap.top();
    }
};


int main() {
    
    return 0;
}