// 88. Merge Sorted Arrays
// Leetcode: https://leetcode.com/problems/merge-sorted-array/

/*
Given 2 arrays sorted in non-decreasing order. Merge two arrays nums1 and nums2 into a single array sorted in non-decreasing order.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

/*
sample i/p: 
5 4
1 3 5 7 9
2 4 6 8

sample o/p: 
1 2 3 4 5 6 7 8 9 
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = n-1, k = m+n-1;
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        }
        else {
            nums1[k--] = nums2[j--];
        }
    }
    while(i >= 0) {
        nums1[k--] = nums1[i--];
    }
    while(j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

void printArray(vector<int>& nums1, int size) {
    for(int i = 0; i < size; i++) {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int m, n;
    cin>>m>>n;

    vector<int> nums1;
    vector<int> nums2;

    for(int i = 0; i < m; i++) {
        int data;
        cin>>data;
        nums1.push_back(data);
    }

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        nums2.push_back(data);
    }

    for(int i = m; i < m+n; i++) {
        nums1[i] = 0;
    }

    merge(nums1, m, nums2, n);

    printArray(nums1, m+n);

    return 0;
}