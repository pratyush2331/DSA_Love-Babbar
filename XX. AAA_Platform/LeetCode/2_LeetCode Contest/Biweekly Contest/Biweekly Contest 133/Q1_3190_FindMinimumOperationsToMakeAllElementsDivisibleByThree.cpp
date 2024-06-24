// 3190. Find Minimum Operations to Make All Elements Divisible by Three
// LeetCode : https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(auto ele : nums) {
            ans += (ele%3 == 0) ? 0 : 1;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}