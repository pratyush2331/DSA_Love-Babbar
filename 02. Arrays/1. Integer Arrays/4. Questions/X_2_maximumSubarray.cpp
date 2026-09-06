// 53. Maximum Subarray [OR] Kadane's Algorithm
// LeetCode : https://leetcode.com/problems/maximum-subarray/

#include<iostream>
using namespace std;

// Kadane's Algorithm
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(int& num : nums) { // iterate through nums; TC:O(n)
            sum += num; // add current_val to sum
            if(sum > maxSum) maxSum = sum; // update maxSum, if required
            if(sum < 0) sum = 0; // reset sum=0 (iff it has -ve val), as it'll only decrease the subarray_sum
        }
        return maxSum;
    }
};

int main() {
    
    return 0;
}