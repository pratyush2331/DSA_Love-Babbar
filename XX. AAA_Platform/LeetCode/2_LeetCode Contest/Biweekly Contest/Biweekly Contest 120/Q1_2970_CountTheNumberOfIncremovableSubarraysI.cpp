// 2970. Count the Number of Incremovable Subarrays I
// LeetCode : https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

#include<bits/stdc++.h>

using namespace std;


// Brute Force based on flesxible constraints... :)

class Solution {
    public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int s = 0; s < n; s++) {
            for(int e = s; e < n; e++) {
                bool flag = 0;
                // left-part
                for(int i = 0; i < s-1; i++) {
                    if(nums[i] >= nums[i+1]) flag = 1;
                }

                // middle-part
                if(s-1 >= 0 && e+1 < n && nums[s-1] >= nums[e+1]) flag = 1;

                // right-part
                for(int i = e+1; i < n-1; i++) {
                    if(nums[i] >= nums[i+1]) flag = 1;
                }

                if(flag == 0) cnt++;
            }
        }
        
        return cnt;
    }
};


int main() {
    

    return 0;
}