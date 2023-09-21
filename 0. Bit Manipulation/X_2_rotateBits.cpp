// Rotate Bits
// GFG : https://practice.geeksforgeeks.org/problems/rotate-bits4524/1

#include<iostream>
using namespace std;


class Solution {
    public:
    vector <int> rotate (int n, int d) {
        int leftShift = n;
        int rightShift = n;
        
        d %= 16;
        int cnt = d;
        while(cnt--) {
            if(leftShift>>15 & 1) {// lmsb is 1
                int mask = ~(1<<16);
                leftShift <<= 1;
                leftShift &= mask;
                leftShift |= 1;
            }
            else {
                leftShift <<= 1;
            }
        }
        
        cnt = d;
        while(cnt--) {
            if(rightShift & 1) { // rmsb is 1
                rightShift >>= 1;
                rightShift |= 1<<15;
            }
            else {
                rightShift >>= 1;
            }
        }
        
        return {leftShift, rightShift};
    }
};


int main() {
    
    return 0;
}