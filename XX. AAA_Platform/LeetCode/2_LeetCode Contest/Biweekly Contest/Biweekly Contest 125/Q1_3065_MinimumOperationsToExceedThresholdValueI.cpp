// 3065. Minimum Operations to Exceed Threshold Value I
// LeetCode : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        
        for(auto ele : nums) {
            if(ele < k) ans++;
        }
        
        return ans;
    }
};


int main() {
    

    return 0;
}