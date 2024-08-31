// 3264. Final Array State After K Multiplication Operations I
// LeetCOde : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            int min_idx = 0;
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] < nums[min_idx]) {
                    min_idx = i;
                }
            }
            nums[min_idx] *= multiplier;
        }
        return nums;
    }
};


int main() {
        
    return 0;
}