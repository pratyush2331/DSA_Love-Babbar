// 2017. Grid Game
// LeetCode : https://leetcode.com/problems/grid-game/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(2n) = O(n)
SC : O(1)
*/
using ll = long long;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll sum0 = accumulate(grid[0].begin(), grid[0].end(), 0LL);

        ll ans = LLONG_MAX, sum1 = 0;
        for(int j = 0; j < grid[0].size(); j++) {
            sum0 -= grid[0][j];
            ans = min(ans, max(sum0, sum1));
            sum1 += grid[1][j];
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