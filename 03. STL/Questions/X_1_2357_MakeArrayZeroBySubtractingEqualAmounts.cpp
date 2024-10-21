// 2357. Make Array Zero by Subtracting Equal Amounts
// LeetCode : https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() - s.count(0);
    }
};


int main() {
    
    return 0;
}