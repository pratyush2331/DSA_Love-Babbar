// 3192. Minimum Operations to Make Binary Array Elements Equal to One II
// LeetCode : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        bool flipped = 0; // not flipped from ith idx to (n-1)th idx
        for(int i = 0; i < n; i++) {
            if(flipped == nums[i]) {
                flipped = !flipped;
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}