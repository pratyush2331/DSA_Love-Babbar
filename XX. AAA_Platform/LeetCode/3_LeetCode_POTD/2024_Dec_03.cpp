// 2109. Adding Spaces to a String
// LeetCode : https://leetcode.com/problems/adding-spaces-to-a-string/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n)
SC : O(n + m)
*/
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    string addSpaces(string s, vector<int>& spaces) {
        string str = "";

        int idx = 0;
        for(int i = 0; i < s.length(); i++) {
            if(idx < spaces.size() && spaces[idx] == i) str += " ", idx++;
            str += s[i];
        }

        return str;
    }
};


int main() {
    
    return 0;
}