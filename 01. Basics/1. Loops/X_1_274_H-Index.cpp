// 274. H-Index
// LeetCode : https://leetcode.com/problems/h-index/

#include<bits/stdc++.h>
using namespace std;


// method-0 : sorting + linear search
/*
TC : O(n.logn) + O(n)
SC : O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i;
        for(i = 0; i < citations.size() && citations[i] > i; i++);
        return i;
    }
};


// method-0 : sorting + binary search
/*
TC : O(n.logn) + O(logn)
SC : O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int ans = 0;
        int s = 0, e = citations.size()-1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(citations[mid] >= mid+1) {
                ans = mid+1;
                s = mid+1;
            }
            else {
                e = mid-1;
            }
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