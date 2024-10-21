// 2410. Maximum Matching of Players With Trainers
// LeetCode : https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n.logn)
SC : O(1) // not cosidering sorting space
*/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // sort both arrays
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        // traverse both & match maximum
        int cnt = 0;
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < players.size() && ptr2 < trainers.size()) {
            if(players[ptr1] <= trainers[ptr2]) { // sucessfull match
                cnt++;
                ptr1++;
                ptr2++;
            }
            else { // increase trainer's level
                ptr2++;
            }
        }
        return cnt;
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