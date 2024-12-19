// 769. Max Chunks To Make Sorted
// LeetCode : https://leetcode.com/problems/max-chunks-to-make-sorted/

#include<bits/stdc++.h>
using namespace std;


// method-1 : neat & clean
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size(), maxi = -1;
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            if(i == maxi) ans++;
        }
        return ans;
    }
};


// method-0 : messy code
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size(), maxi = -1;
        for(int i = 0; i < n; i++) {
            bool flag = 0;
            maxi = max(maxi, arr[i]);
            while(i <= maxi) {
                maxi = max(maxi, arr[i]);
                i++;
                flag = 1;
            }
            if(flag) i--;
            ans++;
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}