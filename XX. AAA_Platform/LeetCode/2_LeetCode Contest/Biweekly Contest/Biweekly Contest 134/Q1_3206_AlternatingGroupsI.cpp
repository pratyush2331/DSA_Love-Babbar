// 3206. Alternating Groups I
// LeetCode : https://leetcode.com/problems/alternating-groups-i

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if(colors[i] == colors[(i+2)%n] && colors[i] != colors[(i+1)%n]) cnt++;
        }
        
        return cnt;
    }
};


int main() {
    
    return 0;
}