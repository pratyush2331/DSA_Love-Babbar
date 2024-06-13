// 295. Find Median from Data Stream
// LeetCode : https://leetcode.com/problems/find-median-from-data-stream/

#include<bits/stdc++.h>
using namespace std;


// using min & max heap
/*
TC : O(logn)
SC : O(n)
*/

class MedianFinder {
    priority_queue<int> left_maxheap;
    priority_queue<int, vector<int>, greater<int>> right_minheap;

public:
    MedianFinder() {}
    
    // always make left_maxheap.size() > right_mihheap.size()
    void addNum(int num) {
        if(left_maxheap.empty() || num < left_maxheap.top()) { // left_maxheap me daalo
            left_maxheap.push(num);
        }
        else { // right_minheap me daalo
            right_minheap.push(num);
        }

        // resizing if needed
        if(left_maxheap.size() > right_minheap.size() + 1) { // left_maxheap se right_minheap me daalo
            right_minheap.push(left_maxheap.top());
            left_maxheap.pop();
        }
        else if(right_minheap.size() > left_maxheap.size()) { // right_minheap se left_maxheap me daalo
            left_maxheap.push(right_minheap.top());
            right_minheap.pop();
        }
    }
    
    double findMedian() {
        if(left_maxheap.size() == right_minheap.size()) {
            if(left_maxheap.empty()) return 0;
            else return (left_maxheap.top() + right_minheap.top()) / 2.0;
        }
        else { // answer is left_maxheap.top()
            return left_maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main() {
    
    return 0;
}