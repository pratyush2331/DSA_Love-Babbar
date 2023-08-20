// GFG : LCM & GCD
/*
Constraints:
1 <= A,B <= 10^18

Example-1:
Input:
A = 5 , B = 10
Output:
10 5

Example-2:
Input:
A = 14 , B = 8
Output:
56 2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<long long> lcmAndGcd(long long A , long long B) { // without Recusrion
            
            long long GCD = 1;
            
            if(A == 0) GCD = B;
            if(B == 0) GCD = A;
            
            long long a = A;
            long long b = B;
            
            while(a != 0 && b != 0) {
                if(a > b) {
                    a = a % b;
                }
                else {
                    b = b % a;
                }
            }
            
            GCD = a>b ? a : b;
            
            long long LCM = (A*B)/GCD;
            
            return {LCM, GCD};
        }
};

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long A, B;

        cin >> A >> B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}