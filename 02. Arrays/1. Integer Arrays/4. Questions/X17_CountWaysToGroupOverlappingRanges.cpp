// 2580. Count Ways to Group Overlapping Ranges
// LeetCode : https://leetcode.com/problems/count-ways-to-group-overlapping-ranges

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n.logn) --> sorting time
SC : O(n.logn) --> sorting space
*/
class Solution {
    const int MOD = 1e9+7;
public:
    int countWays(vector<vector<int>>& ranges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(ranges.begin(), ranges.end());
        int ans = 2;
        int right = ranges[0][1];
        for(auto ele : ranges) {
            if(ele[0] <= right) {
                right = max(right, ele[1]);
            }
            else {
                ans = ans*2 % MOD;
                right = ele[1];
            }
        }
        return  ans;
    }
};


int main() {
    

    return 0;
}