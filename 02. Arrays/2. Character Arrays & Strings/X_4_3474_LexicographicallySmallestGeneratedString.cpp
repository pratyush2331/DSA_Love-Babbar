// 3474. Lexicographically Smallest Generated String
// LeetCode : https://leetcode.com/problems/lexicographically-smallest-generated-string/description/


#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n.m)
SC : O(n + m)
*/
class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<char> ans(n + m - 1, '#');
        vector<bool> fixed(n + m - 1, false);

        // Step 1: apply 'T'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') {
                for(int j = 0; j < m; j++) {
                    if(ans[i+j] != '#' && ans[i+j] != str2[j]) return "";
                    ans[i+j] = str2[j];
                    fixed[i+j] = true;
                }
            }
        }

        // Step 2: fill remaining with 'a'
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '#') ans[i] = 'a';
        }

        // Step 3: handle 'F'
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') {
                bool same = true;
                for(int j = 0; j < m; j++) {
                    if(ans[i+j] != str2[j]) {
                        same = false;
                        break;
                    }
                }

                if(same) {
                    bool changed = false;
                    // try modifying from RIGHTMOST
                    for(int j = m-1; j >= 0; j--) {
                        if(!fixed[i+j]) {
                            ans[i+j] = (str2[j] == 'a') ? 'b' : 'a';
                            changed = true;
                            break;
                        }
                    }

                    if(!changed) return "";
                }
            }
        }

        return string(ans.begin(), ans.end());
    }
};


int main() {
    
    return 0;
}