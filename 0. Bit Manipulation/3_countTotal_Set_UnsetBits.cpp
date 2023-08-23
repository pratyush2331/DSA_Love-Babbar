// Count set and unset bits

#include<bits/stdc++.h>
using namespace std;


int countTotalBit(int n) {
    return log2(n) + 1;
}

int countSetBit(int n) {
    return __builtin_popcount(n);
}

int countUnsetBit(int n) {
    // unset bit = total bit - set bit
    return log2(n) + 1 - __builtin_popcount(n);
}


int main() {
    int n;
    cin >> n;

    cout << " total no. of bits = " << countTotalBit(n) << endl;

    cout << " no. of set bits = " << countSetBit(n) << endl;

    cout << " no. of un-set bits = " << countUnsetBit(n) << endl;
    
    return 0;
}