// 997. Find the Town Judge
// LeetCode : https://leetcode.com/problems/find-the-town-judge/

#include<bits/stdc++.h>
using namespace std;


// method-1
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> deg(n+1, 0); // {indeg + outdeg} --> {trusted + trusting}
        for(auto people : trust) {
            deg[people[0]]--; // trust--
            deg[people[1]]++; // trust++
        }
        int ans = -1, cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == n-1) {
                cnt++;
                ans = i;
            }
        }
        return (cnt == 1) ? ans : -1;
    }
};



// method-0
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>> people(n+1, {0,0}); // {indeg, outdeg}
        for(int i = 0; i < trust.size(); i++) {
            people[trust[i][0]].first++;
            people[trust[i][1]].second++;
        }
        
        int cnt = 0, ans = -1;
        for(int i = 1; i <= n; i++) {
            if(people[i].first == 0 && people[i].second == n-1) {
                cnt++;
                ans = i;
            }
        }

        if(cnt == 1) {
            return ans;
        }
        else {
            return -1;
        }
    }
};


int main() {
    
    return 0;
}