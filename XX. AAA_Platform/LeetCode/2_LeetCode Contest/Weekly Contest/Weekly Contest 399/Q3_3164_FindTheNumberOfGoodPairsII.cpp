// 3164. Find the Number of Good Pairs II
// LeetCode : https://leetcode.com/problems/find-the-number-of-good-pairs-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<long long, long long> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 1; j*j <= nums1[i]; j++) {
                if(j*j == nums1[i]) {
                    mp[j]++;
                }
                else if(nums1[i] % j == 0) {
                    mp[j]++;
                    mp[nums1[i]/j]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += mp[nums2[i] * k];
        }
        return ans;
    }
};


int main() {
    
    return 0;
}