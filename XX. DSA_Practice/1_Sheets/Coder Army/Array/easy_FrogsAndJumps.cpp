// Frogs and Jumps
// GFG : https://www.geeksforgeeks.org/problems/frogs-and-jumps--170647/1

#include<bits/stdc++.h>

using namespace std;


// approach : simliar to sieve
/*
TC : O(N.log(leaves))
SC : O(leaves)
*/
class Solution {
    public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool> vis(leaves+1, false);
        
        for(int i = 0; i < N; i++) {
            int currPos = frogs[i];
            if(!vis[currPos]) {
                for(int j = currPos; j <= leaves; j += currPos) {
                    vis[j] = true;
                }
            }
        }
        
        int cnt = 0;
        for(int i = 1; i <= leaves; i++) {
            if(vis[i] == false) cnt++;
        }
        return cnt;
    }
};


int main() {
    

    return 0;
}