// 703. Kth Largest Element in a Stream
// LeetCode : https://leetcode.com/problems/kth-largest-element-in-a-stream

// TASK : complete KthLargest() constructor and add() function

#include<bits/stdc++.h>
using namespace std;


class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto ele : nums) {
            pq.push(ele);
        }
        while(pq.size() > k) { // removing after k elements
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k) { // removing after k elements
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


int main() {

    return 0;
}