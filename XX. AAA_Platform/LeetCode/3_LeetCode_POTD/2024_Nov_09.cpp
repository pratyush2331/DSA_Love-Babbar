// 3133. Minimum Array End
// LeetCode : https://leetcode.com/problems/minimum-array-end/description/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O((logn)^2)
SC : O(1)
*/
using ll = long long;

class Solution {
public:
    long long minEnd(int n, int x) {
        ll ans = x;
        ll req_num = n-1;
        ll i = 0;
        while(req_num) {
            while(ans & (1LL<<i)) i++; // 1LL is V.V.IMP [to ensure 64-bit shift operation]
            // cout << i << " ";
            ans |= ((req_num&1)<<i);
            i++;
            // cout << ((req_num&1)<<i) << " ";
            req_num >>= 1;
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}