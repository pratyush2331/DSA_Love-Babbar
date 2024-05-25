// 3158. Find the XOR of Numbers Which Appear Twice
// LeetCode : https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele : nums) {
            mp[ele]++;
        }
        int xorSum = 0;
        for(auto ele : mp) {
            if(ele.second == 2) xorSum ^= ele.first;
        }
        return xorSum;
    }
};


int main() {
    
    return 0;
}