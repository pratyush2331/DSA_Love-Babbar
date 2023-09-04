// 

#include<iostream>
using namespace std;

// counting setbits
int countSetBits(int n) {
    int cnt = 0;
    while(n) {
        cnt += (n&1);
        n = n >> 1;
    }
    return cnt;
}

int main() {

    // odd or even number
    int x = 7;
    cout << " x is odd or not : " << (x&1) << endl;

    // no. of bits to be flipped to make number 'a' to 'b'
    int a = 11, b = 15;
    int flippedBits = a ^ b;
    // cout << " no. of bits to be flipped : " << countSetBits(flippedBits) << endl; // counting setbits
    cout << " no. of bits to be flipped : " << __builtin_popcount(flippedBits) << endl; // counting setbits

    // remove the last setbit
    int n = 10;
    cout << " after removing last set bit : " << (n & (n-1)) << endl;
    
    return 0;
}