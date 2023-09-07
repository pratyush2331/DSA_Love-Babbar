// Non Repeating Numbers [GFG] : https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
// 260. Single Number III [LeetCode] : https://leetcode.com/problems/single-number-iii/

#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int> nums) {
        int xorAns = 0;
        for(auto ele : nums) {
            xorAns ^= ele;
        }
        
        // finding msb of xorAns and making mask
        int mask = xorAns & ~(xorAns - 1); // fast
        // int mask = xorAns & -xorAns; // --> slow
        
        // finding 1st number
        int a = 0;
        for(auto ele : nums) {
            if(ele & mask)
                a ^= ele;
        }
        
        // finding 2nd number
        int b = a ^ xorAns;
        
        // returning in ascending order
        if(a < b)
            return {a,b};
        else
            return {b,a};
    }
};


int main() {
    
    return 0;
}