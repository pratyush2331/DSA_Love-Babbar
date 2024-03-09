// 49. Group Anagrams
// LeetCode : https://leetcode.com/problems/group-anagrams/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n)
SC : O(strs.size())
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // SC:O(strs.size())
        for(auto ele : strs) { // TC:O(n)
            string str = ele;
            sort(str.begin(), str.end());
            mp[str].push_back(ele);
        }

        vector<vector<string>> ans; // SC:O(1)
        for(auto ele : mp) { // SC:O(n)
            ans.push_back(ele.second);
        }
        return ans;
    }
};


int main() {
    

    return 0;
}