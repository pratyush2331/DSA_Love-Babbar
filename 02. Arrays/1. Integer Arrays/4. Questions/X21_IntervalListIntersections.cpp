// 986. Interval List Intersections
// LeetCode : https://leetcode.com/problems/interval-list-intersections

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        vector<vector<int>> ans;

        for(int i = 0, j = 0; i < firstList.size() && j < secondList.size(); firstList[i][1] < secondList[j][1] ? i++ : j++) {
            int left =max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if(left <= right) ans.push_back({left, right});
        }

        return ans;
    }
};


int main() {
    

    return 0;
}