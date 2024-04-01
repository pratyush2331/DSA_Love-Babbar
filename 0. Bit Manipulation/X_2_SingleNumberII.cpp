// 137. Single Number II
// LeetCode : https://leetcode.com/problems/single-number-ii

#include<bits/stdc++.h>

using namespace std;


// method-3 : using buckets concept
/*
TC : O(n)
SC : O(1)
*/
// /*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0; // 2 buckets
        for(auto ele : nums) {
            ones = (ones ^ ele) & ~twos;
            twos = (twos ^ ele) & ~ones;
        }
        return ones;
    }
};
// */



// method-2 : using sorting
/*
TC : O(n.logn)
SC : O(logn)
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // TC:O(n.logn), SC:O(logn)
        for(int i = 1; i < nums.size(); i += 3) { // TC:O(n/3)
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];;
    }
};
*/



// method-1 : using bit manipulation
/*
TC : O(32 * n)
SC : O(1)
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto ele : nums) {
                if(ele & (1<<i)) cnt++;
            }
            if(cnt%3 == 1) ans = ans | (1<<i);
        }
        return ans;
    }
};
*/



// method-0 : using map
/*
TC : O(n)
SC : O(n/3) = O(n)
*/
/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto ele : nums) {
            mp[ele]++;
        }
        for(auto ele : mp) {
            if(ele.second == 1) return ele.first;
        }
        return -1;
    }
};
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    

    return 0;
}