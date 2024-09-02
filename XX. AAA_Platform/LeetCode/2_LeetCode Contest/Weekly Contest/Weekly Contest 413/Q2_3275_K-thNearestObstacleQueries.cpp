// 3275. K-th Nearest Obstacle Queries
// LeetCode : https://leetcode.com/problems/k-th-nearest-obstacle-queries/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int> ans(queries.size());
        priority_queue<int> pq; // max heap
        for(int i = 0; (i < k-1) && (i < queries.size()); i++) {
            int x = abs(queries[i][0]);
            int y = abs(queries[i][1]);
            pq.push(abs(x)+abs(y));
            ans[i] = -1;
        }

        // imp edge case
        if(k > queries.size()) return ans;

        // kth ke liye
        pq.push(abs(queries[k-1][0])+abs(queries[k-1][1]));
        ans[k-1] = pq.top();

        for(int i = k; i < queries.size(); i++) {
            int x = abs(queries[i][0]);
            int y = abs(queries[i][1]);
            if((abs(x) + abs(y)) < pq.top()) {
                pq.push(abs(x)+abs(y));
                pq.pop();
            }
            ans[i] = pq.top();
        }
        return ans;
    }
};


int main() {
    
    return 0;
}