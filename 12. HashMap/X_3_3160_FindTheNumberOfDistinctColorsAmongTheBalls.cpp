// 3160. Find the Number of Distinct Colors Among the Balls
// LeetCode : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

#include<bits/stdc++.h>
using namespace std;


// used 2 hash maps (ball --> color; color --> ball[])
/*
TC : O(Q.log(limit))
SC : O(limit)
*/
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> bc; // {ball, color}; SC:O(limit)
        unordered_map<int, set<int>> cb; // {color, balls}; SC:O(limit)
        vector<int> ans(queries.size());
        int i = 0;
        for(auto& qry : queries) { // TC:O(Q.log(limit))
            int ball = qry[0], color = qry[1];
            if(bc.count(ball)) {
                cb[bc[ball]].erase(ball);
                if(cb[bc[ball]].empty()) cb.erase(bc[ball]);
            }
            bc[ball] = color;
            cb[color].insert(ball);
            ans[i++] = cb.size();
        }
        return ans;
    }
};


int main() {
    
    return 0;
}