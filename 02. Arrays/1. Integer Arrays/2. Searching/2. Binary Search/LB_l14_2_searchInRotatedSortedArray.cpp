// 33. Search in Rotated Sorted Array
// LeetCode : https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/956804836/

/*
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getPivot(vector<int>& arr, int n) {
        int s = 0, e = n-1;
        int mid = s + (e-s)/2;
        while(s < e) {
            if(arr[mid] >= arr[0]) s = mid + 1;
            else e = mid;
            mid = s + (e-s)/2;
        }
        return mid; // ya fir, return s
    }

    int binarySearch(vector<int>& arr, int s, int e, int k) {
        int mid = s + (e-s)/2;
        while(s <= e) {
            if(k == arr[mid]) return mid;
            if(k > arr[mid]) s = mid + 1;
            else e = mid - 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int findPosition(vector<int>& arr, int n, int k)
    {
        int ans;
        int pivot = getPivot(arr, n);
        if(k >= arr[pivot] && k <= arr[n-1]) 
            ans = binarySearch(arr, pivot, n-1, k);
        else 
            ans = binarySearch(arr, 0, pivot-1, k);
        return ans;
    }

public:
    int search(vector<int>& nums, int target)
    {
        // Write your code here.
        // Return the position of K in NUMS else return -1.
        int n = nums.size();
        return findPosition(nums, n, target);
    }	
};

int main() {
    vector<int> arr;
    int n;
    cin>>n;

    int k;
    cin>>k;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        arr.push_back(data);
    }

    cout<<search(arr, n, k)<<endl;

    return 0;
}