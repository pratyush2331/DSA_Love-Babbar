// Count Inversions
// GFG : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Coding Ninjas : https://www.codingninjas.com/studio/problems/count-inversions_615

/*
TC : O(n.logn) --> merge sort TC
SC : O(n) --> merge sort space
*/

#include<bits/stdc++.h>

using namespace std;


class Solution {
    int merge(int low, int mid, int high, vector<int>& arr) {
        int n = high - low + 1;
        vector<int> temp(n);
        int idx = 0, i = low, j = mid+1;
        int inversions = 0;
        while(i <= mid && j <= high) {
            if(arr[i] <= arr[j]) temp[idx++] = arr[i++];
            else {
                temp[idx++] = arr[j++];
                // all elements from i to mid are > arr[j]
                inversions += mid - i + 1;
            }
        }
        while(i <= mid) {
            temp[idx++] = arr[i++];
        }
        while(j <= high) {
            temp[idx++] = arr[j++];
        }
        
        for(int idx = 0; idx < n; idx++) {
            arr[low+idx] = temp[idx];
        }
        return inversions;
    }
    
    int mergeSort(int low, int high, vector<int>& arr) {
        if(low >= high) return 0;
        int mid = low + (high - low) / 2;
        int inversions = 0;
        inversions += mergeSort(low, mid, arr);
        inversions += mergeSort(mid+1, high, arr);
        inversions += merge(low, mid, high, arr);
        return inversions;
    }

  public:
    int inversionCount(vector<int> &arr) {
        return mergeSort(0, arr.size()-1, arr);
    }
};


int main() {
    

    return 0;
}