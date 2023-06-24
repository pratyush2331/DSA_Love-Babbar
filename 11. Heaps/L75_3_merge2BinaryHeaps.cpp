// Merge two binary Max heaps
// GFG : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// TC : O(n.Logn), SC : O(n+m)

/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
*/

#include<iostream>
using namespace std;

class Solution{
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]) {
            largest = right;
        }
        
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        
        // step-1: merge both arrays
        vector<int> ans;
        for(auto i : a) {
            ans.push_back(i);
        }
        for(auto i : b) {
            ans.push_back(i);
        }
        
        // step-2: build max heap from merged array
        int size = m+n;
        for(int i = size/2-1; i >= 0; i--) {
            heapify(ans, size, i);
        }
        
        // for(int i = 0; i < size; i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        
        return ans;
    }
};

int main() {
    
    return 0;
}