// 3066. Minimum Operations to Exceed Threshold Value II
// LeetCode : https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/

#include<bits/stdc++.h>

using namespace std;


// approach : using min-heap
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto ele : nums) { // TC: O(n.logn)
            pq.push(ele); // O(logn)
        }
        
        while(pq.size() >= 2 && pq.top() < k) { // TC: O(n.logn)
            int x = (long long)pq.top(); // O(1)
            pq.pop(); // O(logn)
            int y = (long long)pq.top(); // O(1)
            pq.pop(); // O(logn)
            
            long long newVal = (long long)min(x,y) * (long long)2 + (long long)max(x,y);
            pq.push(newVal); // O(logn)
            cnt++;
        }
        
        return cnt;
    }
};


int main() {
    

    return 0;
}