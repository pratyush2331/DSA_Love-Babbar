// 268. Missing Number
// LeetCode : https://leetcode.com/problems/missing-number/

#include<iostream>
using namespace std;


class Solution {
    public:
    // method-2 : XOR operation
    // /*
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i] ^ i;
        }
        return ans ^ nums.size();
    }
    // */



    // method-1 : Brute Foce Improvement
    /*
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
    */



    // method-0 : Brute Foce
    /*
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto ele : nums) {
            sum += ele;
        }

        int n = nums.size();
        return (n*(n+1))/2 - sum;
    }
    */
};


int main() {
    
    return 0;
}