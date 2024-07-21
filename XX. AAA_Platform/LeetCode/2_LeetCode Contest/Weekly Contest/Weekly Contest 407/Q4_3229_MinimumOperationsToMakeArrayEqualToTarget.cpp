// 3229. Minimum Operations to Make Array Equal to Target
// LeetCode : https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        vector<int> diff(n);
        for(int i = 0; i < n; i++) diff[i] = target[i] - nums[i];

        long long ans = abs(diff[0]);
        for(int i = 1; i < n; i++) {
            if((diff[i-1] > 0 && diff[i] > 0) || (diff[i-1] < 0 && diff[i] < 0)) {
                int add = abs(diff[i]) - abs(diff[i-1]);
                if(add > 0) {
                    ans += add;
                }
            }
            else {
                ans += abs(diff[i]);
            }
        }

        return ans;
    }
};


int main() {
    
    return 0;
}