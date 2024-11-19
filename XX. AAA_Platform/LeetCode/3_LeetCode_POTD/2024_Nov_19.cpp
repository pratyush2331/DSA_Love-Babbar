// 2461. Maximum Sum of Distinct Subarrays With Length K
// LeetCode : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include<bits/stdc++.h>
using namespace std;


// 2 pointer + map
/*
TC : O(n)
SC : O(k)
*/

using ll = long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll sum = 0;
        // computing 1st k-size subarray
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }

        ll ans = (mp.size() == k) ? sum : 0;

        // computing rest k-size subarrays
        for(int i = k; i < nums.size(); i++) {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);

            sum += nums[i];
            sum -= nums[i-k];
            if(mp.size() == k) ans = max(ans, sum);
        }
        return ans;
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