// 

#include<bits/stdc++.h>
using namespace std;

int solve(string L, string R) {
    if(L == R) { // edge case
        return (L[0] == L[L.length()-1]) ? 1 : 0;
    }
    int a1 = L[0] - '0', a2 = L[L.length()-1] - '0';
    int b1 = R[0] - '0', b2 = R[R.length()-1] - '0';

    int ld = 0;
    if(L.length() == 1) {
        ld = a1;
    }
    else {
        ld = (a2 < a1) ? a1+9 : a1+10;
    }
    int rd = 0;
    if(R.length() == 1) {
        rd = b1;
    }
    else {
        rd = (b2 < b1) ? b1+9 : b1+10;
    }
    return (ld <= rd) ? rd-ld : -1;
}

int main() {
    string L, R;
    cin >> L >> R;
    
    cout << solve(L, R) << "\n";
    
    return 0;
}