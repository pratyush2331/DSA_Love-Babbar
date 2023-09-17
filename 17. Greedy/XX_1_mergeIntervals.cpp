// 56. Merge Intervals
// LeetCode : https://leetcode.com/problems/merge-intervals/

#include<iostream>
using namespace std;


class Solution {
    public:
    // Optimal Solution
    // /*
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size(); i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }

        return ans;
    }
    // */



    // Brute Force
    /*
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int i = 0;
        int start = -1, end = -1;
        while(i < intervals.size()-1) {
            start = intervals[i][0];
            end = intervals[i][1];
            while(i < intervals.size()-1 && end >= intervals[i+1][0]) {
                start = min(start, intervals[i+1][0]);
                end = max(end, intervals[i+1][1]);
                i++;
            }
            ans.push_back({start, end});
            i++;
        }

        if(i == intervals.size()-1) {
            if(intervals[i][0] >= end) {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }

        return ans;
    }
    */
};


int main() {
    
    return 0;
}