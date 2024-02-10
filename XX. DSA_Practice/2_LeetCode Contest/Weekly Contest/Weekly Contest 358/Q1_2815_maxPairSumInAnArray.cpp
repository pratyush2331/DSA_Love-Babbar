// 2815. Max Pair Sum in an Array
// LeetCode : https://leetcode.com/contest/weekly-contest-358/problems/max-pair-sum-in-an-array/

#include<iostream>
using namespace std;


class Solution {
    int getMaxDigit(int n) {
        int maxi = 0;
        while(n) {
            maxi = max(maxi, n%10);
            n /= 10;
        }
        return maxi;
    }
    
    public:
    int maxSum(vector<int>& nums) {
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(getMaxDigit(nums[i]) == getMaxDigit(nums[j])) {
                    maxi = max(maxi, nums[i] + nums[j]);
                }
            }
        }
        return maxi;
    }
};


int main() {
    
    return 0;
}