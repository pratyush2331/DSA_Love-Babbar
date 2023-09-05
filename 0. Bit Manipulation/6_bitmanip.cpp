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

    // swapping 2 numbers
    int n1 = -5, n2 = 10;
    cout << n1 << " " << n2 << endl;
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
    cout << n1 << " " << n2 << endl;

    // get i-th bit
    int num = 13, i = 2;
    cout << (bool)(num & (1 << i)) << endl;

    // set the i-th bit
    cout << (num | (1 << i)) << endl;

    // clear the i-th bit
    cout << (num & ~(1 << i)) << endl;

    // toggle the i-th bit
    cout << (num ^ (1 << i)) << endl;
    
    return 0;
}