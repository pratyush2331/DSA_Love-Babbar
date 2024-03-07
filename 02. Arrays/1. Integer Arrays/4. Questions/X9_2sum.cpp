// 1. Two Sum
// LeetCode : https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>

using namespace std;


// method-1 : using unordered_map in one pass
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end() && i != mp[target - nums[i]]) { // found
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};



// method-0 : brute force
/*
TC : O(n^2)
SC : O(1)
*/
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {-1,-1};
    }
};
*/


int main() {
    

    return 0;
}