// 2208. Minimum Operations to Halve Array Sum
// LeetCode : https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

#include<bits/stdc++.h>
using namespace std;


// method : using heap
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq; // max heap
        double currSum = 0, totalSum = 0;
        for(int& num : nums) {
            pq.push(num);
            totalSum += num;
        }

        currSum = totalSum;
        totalSum /= 2;
        int ops = 0;
        while(currSum > totalSum) {
            double top = pq.top();
            pq.pop();

            pq.push(top/2);
            currSum -= top / 2;
            ops++;
        }
        return ops;
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