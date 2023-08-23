// Number of 1 Bits
// GFG : https://practice.geeksforgeeks.org/problems/set-bits0143/1

#include<iostream>
using namespace std;


class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        
        //method-1
        return __builtin_popcount(N);
        
        // method-0
        // int c = 0;
        // while(N) {
        //     if(N&1) c++;
        //     N = N >> 1;
        // }
        // return c;
    }
};


int main() {
    
    return 0;
}