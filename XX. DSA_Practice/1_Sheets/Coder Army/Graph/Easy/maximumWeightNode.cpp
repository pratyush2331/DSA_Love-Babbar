// Maximum Weight Node
// GFG : https://practice.geeksforgeeks.org/problems/maximum-weight-node--170645/1

#include<bits/stdc++.h>

using namespace std;


class Solution
{
    public:
    int maxWeightCell(int N, vector<int> Edge) {
        vector<int> weight(N, 0);
        
        for(int i = 0; i < Edge.size(); i++) {
            if(Edge[i] != -1) {
                weight[Edge[i]] += i;
            }
        }
        
        int maxi = 0, maxIndex = 0;
        for(int i = 0; i < N; i++) {
            if(weight[i] >= maxi) {
                maxi = weight[i];
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
};


int main() {
    

    return 0;
}