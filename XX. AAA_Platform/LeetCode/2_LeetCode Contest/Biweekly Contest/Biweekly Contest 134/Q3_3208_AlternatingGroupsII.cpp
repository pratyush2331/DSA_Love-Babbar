// 3208. Alternating Groups II
// LeetCode : https://leetcode.com/problems/alternating-groups-ii

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k; i++) { // push k elements to colors array
            colors.push_back(colors[i]);
        }
        int n = colors.size(); // new size
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(cnt < k) {
                if(i+1 < n && colors[i] == colors[i+1]) cnt = 1;
                else cnt++;  // count current element
            }
            else if(cnt == k) {
                ans++;
                if(i+1 < n && colors[i] == colors[i+1]) cnt = 1;
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}