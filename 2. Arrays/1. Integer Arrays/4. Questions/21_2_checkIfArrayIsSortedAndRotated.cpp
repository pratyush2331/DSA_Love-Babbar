// 1752. Check if Array is Sorted and Rotated
// LeetCode : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/

/*
Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
*/


#include<iostream>
#include<vector>

using namespace std;


// TC: O(n),      SC: O(1)
bool check(vector<int>& nums) {
    int n = nums.size();

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] > nums[(i+1)%n]) count++;
    }

    return count <= 1;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        nums.push_back(data);
    }

    cout<<check(nums)<<endl;

    return 0;
}