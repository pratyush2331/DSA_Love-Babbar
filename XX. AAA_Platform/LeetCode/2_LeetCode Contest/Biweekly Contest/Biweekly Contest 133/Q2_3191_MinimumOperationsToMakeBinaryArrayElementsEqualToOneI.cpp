// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// LeetCode : https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

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
        for(int i = 0; i < n; i++) { // doing it for all elements
            if(nums[i] == 0 && i+2 < n) { // doing it in size of 3
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
                cnt++;
            }
        }
        if(nums[n-2] == 0 || nums[n-1] == 0) { // if last or second last ele is still 0
            return -1;
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}