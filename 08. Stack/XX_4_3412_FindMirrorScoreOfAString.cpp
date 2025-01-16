// 3412. Find Mirror Score of a String
// LeetCode : https://leetcode.com/problems/find-mirror-score-of-a-string/

#include<bits/stdc++.h>
using namespace std;


// using map + stack
/*
TC : O(n)
SC : O(n)
*/
using ll = long long;
class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<char, char> mirror; // SC:O(26) = SC:O(1)
        for(char ch = 'a'; ch <= 'z'; ch++) { // TC:O(26) = O(1)
            mirror[ch] = 'a' + ('z' - ch);
        }
        
        ll score = 0;
        unordered_map<char, stack<int>> unmarked; // SC:O(n)
        for(int i = 0; i < s.length(); i++) { // TC:O(n)
            char mir = mirror[s[i]];
            if(unmarked[mir].size()) {
                int j = unmarked[mir].top();
                unmarked[mir].pop();
                score += (i - j);
            }
            else{
                unmarked[s[i]].push(i);
            }
        }
        return score;
    }
};


int main() {
    
    return 0;
}