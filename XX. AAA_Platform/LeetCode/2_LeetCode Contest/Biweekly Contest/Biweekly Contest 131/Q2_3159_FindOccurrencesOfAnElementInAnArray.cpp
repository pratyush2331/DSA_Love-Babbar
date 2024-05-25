// 3159. Find Occurrences of an Element in an Array
// LeetCode : https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> idx; // will store idx for x
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == x) {
                idx.push_back(i);
            }
        }
        int cnt = idx.size(); // count/freq of x
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            if(queries[i] > cnt) ans.push_back(-1);
            else ans.push_back(idx[queries[i]-1]);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}