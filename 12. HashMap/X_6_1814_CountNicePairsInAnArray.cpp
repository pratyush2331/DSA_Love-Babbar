// 1814. Count Nice Pairs in an Array
// LeetCode : https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int MOD = 1e9+7;
    int rev(int num) {
        string str = to_string(num);
        reverse(str.begin(), str.end());
        return stoi(str);
    }

public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int& ele : nums) {
            mp[ele - rev(ele)]++;
        }
        int np = 0;
        for(auto& ele : mp) np = (np + (1LL * ele.second * (ele.second - 1) / 2) % MOD) % MOD;
        return np % MOD;
    }
};


int main() {
    
    return 0;
}