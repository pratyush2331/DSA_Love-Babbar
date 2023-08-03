// Chocolate Distribution Problem
// GFG : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include<iostream>
using namespace std;


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        sort(a.begin(), a.end());
        
        // sliding window
        int i = 0, j = m-1;
        int mini = INT_MAX;
        while(j < n) {
            int diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        
        return mini;
    }   
};


int main() {
    
    return 0;
}