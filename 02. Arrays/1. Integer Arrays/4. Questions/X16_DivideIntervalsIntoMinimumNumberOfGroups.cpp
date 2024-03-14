// 2406. Divide Intervals Into Minimum Number of Groups
// LeetCode : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for(const auto &ele : intervals) {
            if(!pq.empty() && pq.top() < ele[0]) {
                pq.pop();
            }
            pq.push(ele[1]);
        }

        return pq.size();
    }
};


int main() {
    

    return 0;
}