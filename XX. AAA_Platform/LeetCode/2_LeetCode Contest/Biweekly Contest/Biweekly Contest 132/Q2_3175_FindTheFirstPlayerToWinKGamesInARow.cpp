// 3175. Find The First Player to win K Games in a Row
// LeetCode : https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();

        deque<int> q;
        pair<int,int> maxi;
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if(skills[i] > temp) {
                temp = skills[i];
                maxi = {skills[i], i};
            }
            q.push_back(i);
        }
        
        if(k >= maxi.second) return maxi.second;

        int current_winner = q[0];
        int win_count = 0;
        while (win_count < k) {
            int player1 = q.front();
            q.pop_front();
            int player2 = q.front();
            q.pop_front();
            
            if(skills[player1] > skills[player2]) {
                q.push_back(player2);
                q.push_front(player1);
                if(current_winner == player1) {
                    win_count++;
                }
                else {
                    current_winner = player1;
                    win_count = 1;
                }
            }
            else {
                q.push_back(player1);
                q.push_front(player2);
                if(current_winner == player2) {
                    win_count++;
                }
                else {
                    current_winner = player2;
                    win_count = 1;
                }
            }
        }
        
        return current_winner;
    }
};


int main() {
    
    return 0;
}