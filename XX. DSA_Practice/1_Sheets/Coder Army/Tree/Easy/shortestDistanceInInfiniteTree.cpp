// Shortest distance in infinite tree
// GFG : https://practice.geeksforgeeks.org/problems/find-the-distance-between-two-nodes4402/1

#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    int distance(int X, int Y) {
        int cnt = 0;
        while(X != Y) {
            cnt++;
            
            if(X > Y) {
                X = X>>1;
            }
            else {
                Y = Y>>1;
            }
        }
        return cnt;
    }
};


int main() {
    

    return 0;
}