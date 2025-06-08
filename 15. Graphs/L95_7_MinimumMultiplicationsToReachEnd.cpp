// Minimum Multiplications to reach End
// GFG : https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

#include<bits/stdc++.h>
using namespace std;


// simple BFS, or modified dijkstra's algorithm
class Solution {
  const int MOD = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<bool> vis(MOD, 0);
        queue<int> q;
        q.push(start);
        int steps = 0;
        while(!q.empty()) {
            int x = q.size();
            while(x--) {
                int front = q.front();
                q.pop();
                
                if(front == end) return steps;
                
                for(int ele : arr) {
                    int newEle = (ele * front) % MOD;
                    if(!vis[newEle]) {
                        q.push(newEle);
                        vis[newEle] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


int main() {
    
    return 0;
}