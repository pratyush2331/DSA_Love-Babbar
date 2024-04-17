// 78. subsets
// LeetCode : https://leetcode.com/problems/subsets/

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

#include<iostream>
#include<vector>
using namespace std;


// method-1 : using bit manipulation
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int k = (1 << n);
    for(int i = 0; i < k; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) temp.push_back(nums[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}


// method-0 : using recursion
/*
void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
    // base case
    if(index == nums.size()) {
        ans.push_back(output);
        return;
    }
    
    // exclude
    solve(nums, output, index+1, ans);
    
    // include
    output.push_back(nums[index]);
    solve(nums, output, index+1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, 0, ans);
    return ans;
}
*/


int main() {
    vector<int> nums;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }

    vector<vector<int>> ans = subsets(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}