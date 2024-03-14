// 763. Partition Labels
// LeetCode : https://leetcode.com/problems/partition-labels

#include<bits/stdc++.h>

using namespace std;


// method-1 : optimal approach
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    vector<int> partitionLabels(string s) {
        vector<int> ans; // SC:O(1)

        // we got the {start,end} of all alphabets
        unordered_map<char, int> mp; // will store last occ of alphabet --> SC:O(2n)
        for(int i = 0; i < s.length(); i++) { // TC:O(n)
            mp[s[i]] = i;
        }

        // merge intervals logic
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++) {
            right = max(right, mp[s[i]]);
            if(i == right) {
                ans.emplace_back(right - left + 1);
                left = i+1;
            }
        }

        return ans;
    }
};



// method-0 : brute force
/*
TC : O(n)
SC : O(n)
*/
/*
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans; // SC:O(1)

        // we got the {start,end} of all alphabets
        unordered_map<char, vector<int>> mp; // SC:O(3n)
        for(int i = 0; i < s.length(); i++) { // TC:O(n)
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = {i, i};
            else mp[s[i]][1] = i;
        }

        // merge intervals logic
        vector<vector<int>> intervals; // SC:O(2n)
        for(auto ele : mp) {
            // cout << ele.first << " " << ele.second.first << " " << ele.second.second << "\n";
            intervals.push_back(ele.second);
        }

        sort(intervals.begin(), intervals.end()); // TC:O(n.logn), SC:O(n.logn) --> n <= 26
        vector<vector<int>> newInterval; // SC:O(2n)
        int left = intervals[0][0], right = intervals[0][1];
        for(auto ele : intervals) { // TC:O(n)
            // cout << ele[0] << " " << ele[1] << "\n";
            if(ele[0] <= right) {
                right = max(right, ele[1]);
            }
            else {
                newInterval.push_back({left,right});
                left = ele[0];
                right = ele[1];
            }
        }
        newInterval.push_back({left,right});
        
        for(auto ele : newInterval) { // TC:O(n)
            ans.push_back(ele[1] - ele[0] + 1);
        }

        return ans;
    }
};
*/


int main() {
    

    return 0;
}