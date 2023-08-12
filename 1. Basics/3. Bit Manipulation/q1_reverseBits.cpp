// 190. Rverse Bits
// LeetCode : https://leetcode.com/problems/reverse-bits/description/

#include<iostream>
using namespace std;

class Solution {
    public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans;
        for(int i = 0; i < 32; i++) {
            ans = ans << 1;
            bool bit = n & 1;
            ans = ans | bit;
            n = n >> 1;
            // cout << bit << " ";
        }
        return ans;
    }
};

int main() {
    
    return 0;
}