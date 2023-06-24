// LeetCode-46 : Permutations
/*
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans) {
    // base case
    if(index >= nums.size()) {
        ans.push_back(nums);
        return;
    }
    
    for(int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        solve(nums, index+1, ans);
        // backtracking
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

int main() {
    vector<int> nums;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++) {
        int data;
        cin >> data;
        nums.push_back(data);
    }

    vector<vector<int>> ans = permute(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}