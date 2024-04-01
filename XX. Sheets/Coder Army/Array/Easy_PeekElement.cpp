// Peak element
// GFG : https://www.geeksforgeeks.org/problems/peak-element/1

#include<bits/stdc++.h>

using namespace std;


/* The function should return the index of any
   peak element present in the array */

// Method-1 : Better Solution
/*
TC : O(logn)
SC : O(1)
*/
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int s = 0, e = n-1;
        int mid = s + (e-s)/2;
        while(s <= e) {
            if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])) return mid;
            else if(arr[mid] >= arr[mid-1]) s = mid+1;
            else e = mid-1;
            mid = s + (e-s)/2;
        }
        return -1;
    }
};



// Method-0 : Brute Force
/*
TC : O(n)
SC : O(1)
*/
/*
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int prev = 0;
        int index = 0;
        for(int i = 0; i < n; i++) {
          if(arr[i] >= prev) {
              index = i;
          }
          prev = arr[i];
        }
        return index;
    }
};
*/


int main() {
    

    return 0;
}