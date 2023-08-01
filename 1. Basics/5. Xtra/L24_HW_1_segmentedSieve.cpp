// not working
// Segmented Sieve
// why to use over sieve? : because size of array can not be greater than 10^8
/*
t -> test case
L, R -> lower bound & upper bound of interval

constraints:
1 <= L <= U <= 10^9
R - L <= 10^6
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



int main() {
    int L, R;
    cout << "Enter lower & upper limit : ";
    cin >> L >> R;

    segSieve(L, R);

    return 0;
}
