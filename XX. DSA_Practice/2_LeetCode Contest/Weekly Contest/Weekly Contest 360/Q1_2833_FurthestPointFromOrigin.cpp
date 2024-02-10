// 2833. Furthest Point From Origin
// LeetCode : https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

#include<iostream>
using namespace std;


class Solution {
    public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int cntL = 0, cntR = 0, cnt_= 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L') cntL++;
            else if(moves[i] == 'R') cntR++;
            else if(moves[i] == '_') cnt_++;
        }
        return abs(cntL - cntR) + cnt_;
    }
};


int main() {
    
    return 0;
}