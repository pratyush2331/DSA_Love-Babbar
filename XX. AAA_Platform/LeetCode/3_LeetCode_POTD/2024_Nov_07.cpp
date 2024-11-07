// 2275. Largest Combination With Bitwise AND Greater Than Zero
// LeetCode : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<int> ones_pos(25, 0);
        for(int i = 0; i < n; i++) {
            int temp = candidates[i];
            int pos = 0;
            while(temp) {
                if(temp&1) ones_pos[pos]++;
                temp >>= 1;
                pos++;
            }
        }
        int maxi = 0;
        for(int i = 0; i < 25; i++) maxi = max(maxi, ones_pos[i]);
        return maxi;
    }
};


int main() {
    
    return 0;
}