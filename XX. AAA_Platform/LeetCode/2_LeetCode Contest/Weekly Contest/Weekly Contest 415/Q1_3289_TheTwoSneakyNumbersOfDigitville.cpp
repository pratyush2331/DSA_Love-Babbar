// 3289. The Two Sneaky Numbers of Digitville
// LeetCode : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto ele : nums) {
            mp[ele]++;
        }
        vector<int> ans;
        for(auto ele : mp) {
            if(ele.second == 2) ans.push_back(ele.first);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}