// 56. Merge Intervals
// LeetCode : https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>

using namespace std;


// same approach with better readability
/*
TC : O(n.logn)
SC : O(n) // including output
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // SC:O(n)
        sort(intervals.begin(), intervals.end()); // TC:O(n.logn), SC:O(logn)
        for(const auto& interval : intervals) { // TC:O(n)
            if(ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

// method : greedy
/*
TC : O(n.logn)
SC : O(n) // including output
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // SC:O(n)
        sort(intervals.begin(), intervals.end()); // TC:O(n.logn), SC:O(logn)
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) { // TC:O(n)
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                ans.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};


int main() {
    

    return 0;
}