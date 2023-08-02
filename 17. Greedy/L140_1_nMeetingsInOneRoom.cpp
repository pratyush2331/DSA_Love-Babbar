// N meetings in one room
// GFG : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include<iostream>
using namespace std;


/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
    // custom comparator
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    
    public:
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int count = 1;
        int ansEnd = v[0].second;
        for(int i = 1; i < n; i++) {
            if(v[i].first > ansEnd) {
                count++;
                ansEnd = v[i].second;
            }
        }
        
        return count;
    }
};


int main() {
    
    return 0;
}