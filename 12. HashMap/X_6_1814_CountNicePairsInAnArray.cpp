// 1814. Count Nice Pairs in an Array
// LeetCode : https://leetcode.com/problems/count-nice-pairs-in-an-array/

#include<bits/stdc++.h>
using namespace std;


// method : using HashMap
/*
TC : O(n)
SC : O(n)
*/
class Solution {
    int MOD = 1e9+7;
    int rev(int num) { // TC:O(9)
        string str = to_string(num);
        reverse(str.begin(), str.end());
        return stoi(str);
    }

public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp; // SC:O(n)
        for(int& ele : nums) { // TC:O(n*9) = O(n)
            mp[ele - rev(ele)]++;
        }
        int np = 0;
        for(auto& ele : mp) np = (np + (1LL * ele.second * (ele.second - 1) / 2) % MOD) % MOD; // TC:O(n)
        return np % MOD;
    }
};


int main() {
    
    return 0;
}