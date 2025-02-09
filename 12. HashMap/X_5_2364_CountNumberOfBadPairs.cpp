// 2364. Count Number of Bad Pairs
// LeetCode : https://leetcode.com/problems/count-number-of-bad-pairs/

#include<bits/stdc++.h>
using namespace std;


// method : using HashMap
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // total bad pairs = total pairs - total good pairs
        int n = nums.size();
        unordered_map<int, int> mp; // SC:O(n)
        for(int i = 0; i < n; i++) { // TC:O(n)
            mp[nums[i] - i]++;
        }
        long long tgp = 0;
        for(auto& ele : mp) tgp += (ele.second*(1LL*ele.second-1))/2; // TC:O(n)
        return (1LL*n*(n-1))/2 - tgp;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}