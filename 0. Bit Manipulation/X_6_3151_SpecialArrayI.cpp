// 3151. Special Array I
// LeetCode : https://leetcode.com/problems/special-array-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++) {
            if((nums[i]&1) ^ (nums[i+1]&1) == 0) return 0;
        }
        return 1;
    }
};


int main() {
    
    return 0;
}