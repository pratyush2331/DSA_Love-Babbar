// 3169. Count Days Without Meetings
// LeetCode : https://leetcode.com/problems/count-days-without-meetings/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // TC:(n.logn)
        int cnt = 0, day_start = 0, day_end = 0;
        for(int i = 0; i < meetings.size(); i++) { // TC:(n)
            int meet_start = meetings[i][0], meet_end = meetings[i][1];
            cnt += (meet_start <= day_end+1) ? 0 : meet_start - day_end - 1;
            day_end = max(day_end, meet_end);
            day_start = meet_end+1;
        }
        cnt += days-day_end;
        return cnt;
    }
};


int main() {
    
    return 0;
}