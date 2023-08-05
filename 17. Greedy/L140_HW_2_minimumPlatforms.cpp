// Minimum Platforms
// GFG : https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<iostream>
using namespace std;


class Solution {
    // method-1 : 2-pointer approach
    /*
    TC : O(n.logn)
    SC : O(1)
    */
    // /*
    public:
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here

        // Sort both arrays - arr[], dep[]
        sort(arr, arr + n);
        sort(dep, dep + n);

        
        int i = 1, j = 0;
        int platforms = 1;
        while(i < n && j < n) {
            if(arr[i] <= dep[j])
                platforms++;
            else
                j++;
            i++;
        }
        
        return platforms;
    }
    // */
    
    
    
    // method-0 : priority queue
    /*
    TC : O(n.logn)
    SC : O(n)
    */
    /*
    public:
    int findPlatform(int arr[], int dep[], int n) {
    	// Your code here
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], dep[i]};
        }

        // Sort based on arrival time
        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(v[0].second);
        int platforms = 1;

        for (int i = 1; i < n; i++) {
            if (v[i].first <= pq.top()) {
                platforms++;
            } else {
                pq.pop();
            }
            pq.push(v[i].second);
        }

        return platforms;
    }
    */
};


int main() {
    
    return 0;
}