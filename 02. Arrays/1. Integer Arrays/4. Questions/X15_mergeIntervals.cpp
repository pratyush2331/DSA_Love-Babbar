// 56. Merge Intervals
// LeetCode : https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>

using namespace std;


// method : greedy
/*
TC : O(n.logn)
SC : O(n.logn)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end()); // TC:O(n.logn), SC:O(n.logn)

        vector<vector<int>> ans;
        int left = intervals[0][0], right = intervals[0][1]; // will store values
        for(int i = 1; i < n; i++) { // TC:O(n)
            if(intervals[i][0] <= right) {
                right = max(right, intervals[i][1]);
            }
            else {
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back({left, right});

        return ans;
    }
};


int main() {
    

    return 0;
}