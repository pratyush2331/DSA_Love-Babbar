// Maximum Meetings in One Room
// LeetCode : https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution{
    public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F){
        vector<int> ans;
        
        vector<vector<int>> v(N, vector<int>(3));
        for(int i = 0; i < N; i++) {
            v[i][0] = F[i]; // finish time
            v[i][1] = S[i]; // start time
            v[i][2] = i;    // index
        }
        
        sort(v.begin(), v.end());
        ans.push_back(v[0][2] + 1);
        int curr = v[0][0];
        
        for(int i = 1; i < N; i++) {
            if(v[i][1] > curr) {
                ans.push_back(v[i][2] + 1);
                curr = v[i][0];
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    
    return 0;
}