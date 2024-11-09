// 1829. Maximum XOR for Each Query
// LeetCode : https://leetcode.com/problems/maximum-xor-for-each-query/description

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int maxNum = (1 << maximumBit) - 1;
        int xorSum = 0;
        for(auto ele : nums) {
            xorSum ^= ele;
            ans.emplace_back(maxNum ^ xorSum);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    
    return 0;
}