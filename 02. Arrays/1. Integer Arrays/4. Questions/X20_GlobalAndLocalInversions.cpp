// 775. Global and Local Inversions
// LeetCode : https://leetcode.com/problems/global-and-local-inversions

#include<bits/stdc++.h>

using namespace std;


// method-1 : optimal solution
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(abs(nums[i] - i) > 1) return false;
        }

        return true;;
    }
};



// method-0 : brute force
/*
TC : O(n.logn) --> merge sort TC
SC : O(n) --> merge sort SC
*/
/*
class Solution {
    long long global = 0, local = 0;

    void merge(vector<int>& arr, int s, int e) {
        int mid = s + (e-s)/2;

        int len1 = mid-s+1;
        int len2 = e-mid;

        long long* arr1 = new long long[len1];
        long long* arr2 = new long long[len2];

        int mainArrayIndex = s;
        for(int i = 0; i < len1; i++) {
            arr1[i] = arr[mainArrayIndex++];
        }
        for(int i = 0; i < len2; i++) {
            arr2[i] = arr[mainArrayIndex++];
        }

        // merge 2 sorted arrays
        int i = 0, j = 0;
        mainArrayIndex = s;
        while(i < len1 && j < len2) {
            if(arr1[i] <= arr2[j]) {
                arr[mainArrayIndex++] = arr1[i++];
            }
            else {
                arr[mainArrayIndex++] = arr2[j++];
                global += ((long long)mid - (long long)s - (long long)i + (long long)1);
            }
        }
        while(i < len1) {
            arr[mainArrayIndex++] = arr1[i++];
        }
        while(j < len2) {
            arr[mainArrayIndex++] = arr2[j++];
        }

        delete[] arr1;
        delete[] arr2;
    }

    void mergeSort(vector<int>& arr, int s, int e) {
        // base case
        if(s >= e) return ;

        int mid = s + (e-s)/2;

        if((long long)arr[mid] > (long long)arr[mid+1]) local++;

        // left part sort krna h
        mergeSort(arr, s, mid);

        // right part sort krna h
        mergeSort(arr, mid+1, e);

        // merge krna h
        merge(arr,s, e);
    }

public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    bool isIdealPermutation(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        // cout << global << " " << local << "\n";

        return global == local;
    }
};
*/


int main() {
    

    return 0;
}