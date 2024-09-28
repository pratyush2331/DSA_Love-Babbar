// 3300. Minimum Element After Replacement With Digit Sum
// LeetCode : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            int sum = 0;
            while(temp) {
                sum += (temp%10);
                temp /= 10;
            }
            mini = min(mini, sum);
        }
        return mini;
    }
};


int main() {
    
    return 0;
}