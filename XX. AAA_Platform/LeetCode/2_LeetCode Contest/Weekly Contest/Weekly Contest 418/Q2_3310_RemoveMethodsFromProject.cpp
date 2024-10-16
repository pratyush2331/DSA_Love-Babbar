// 3310. Remove Methods From Project
// LeetCode : https://leetcode.com/problems/remove-methods-from-project

#include<bits/stdc++.h>
using namespace std;


/*
n --> no. of nodes
m --> no. of edges
TC : O(n+m)
SC : O(n+m)
*/
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations){
        // step 1: create adjacency lists for direct invocationss
        vector<vector<int>> directInvokes(n);
        for(const auto& invoke : invocations){
            int u = invoke[0];
            int v = invoke[1];
            directInvokes[u].emplace_back(v);
        }

        // step 2: use BFS to mark all methods starting from method k as suspicious
        vector<bool> markedSuspicious(n, false);
        queue<int> suspiciousQueue;
        suspiciousQueue.push(k);
        markedSuspicious[k] = true;

        while(!suspiciousQueue.empty()){
            int currentMethod = suspiciousQueue.front();
            suspiciousQueue.pop();
            for(int invokedMethod : directInvokes[currentMethod]){
                if(!markedSuspicious[invokedMethod]){
                    markedSuspicious[invokedMethod] = true;
                    suspiciousQueue.push(invokedMethod);
                }
            }
        }

        // step 3: ensure no external method (not marked suspicious) invokes a suspicious method
        bool isRemovable = true;
        for(int i = 0; i < n; i++){
            if(!markedSuspicious[i]){
                for(int invoked : directInvokes[i]){
                    if(markedSuspicious[invoked]){
                        isRemovable = false;
                        break;
                    }
                }
            }
            if(!isRemovable) break;
        }

        // step-4: if we cannot safely remove the suspicious methods, return all methods
        if(!isRemovable){
            vector<int> allMethods(n);
            for(int i = 0; i < n; i++){
                allMethods[i] = i;
            }
            return allMethods;
        }

        // otherwise, return the list of remaining non-suspicious methods
        vector<int> result;
        for(int i = 0; i < n; ++i){
            if(!markedSuspicious[i]){
                result.emplace_back(i);
            }
        }

        return result;
    }
};


int main() {
    
    return 0;
}