// 852. Peak Index in a Mountain Array
// LeetCode :  https://leetcode.com/problems/peak-index-in-a-mountain-array/

// NOTE: guarenteed mountain array (in Input)
/*
Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
*/

#include<iostream>
using namespace std;

int peakIndexInMountainArray(int arr[], int n);

int main(){

    int arr[20];
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    cout<<peakIndexInMountainArray(arr, n)<<endl;

    return 0;
}

int peakIndexInMountainArray(int arr[], int n) {
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s < e) {
        if(arr[mid] < arr[mid+1]) s = mid+1;
        else e = mid;
        mid = s + (e-s)/2;
    }
    return mid; // ya fir, return s
}