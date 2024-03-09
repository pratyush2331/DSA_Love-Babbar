// 1338. Reduce Array Size to The Half
// LeetCode : https://leetcode.com/problems/reduce-array-size-to-the-half/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(2.n.logn) = O(n.logn)
SC : O(2n) = O(n)
*/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // store in map to cnt frequency and val
        unordered_map<int, int> mp; // SC:O(n)
        for(auto ele : arr) { // TC:O(n)
            mp[ele]++;
        }
        
        // greedy --> max heap
        priority_queue<int> pq; // {freq_each_ele} --> SC:O(n)
        for(auto ele : mp) { // TC:O(n.logn)
            pq.push(ele.second);
        }

        int req = 0;
        int ans = 0;
        while(!pq.empty()) { // TC:O(n.logn)
            ans++;
            req += pq.top();
            pq.pop();
            if(req >= arr.size()/2) break;
        }
        return ans;
    }
};


int main() {
    

    return 0;
}