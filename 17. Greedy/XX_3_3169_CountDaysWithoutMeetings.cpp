// 3169. Count Days Without Meetings
// LeetCode : https://leetcode.com/problems/count-days-without-meetings/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using Line Sweep logic
/*
TC : O(n.logn)
SC : O(1) // not considering sorting space
*/
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;

        for (auto& meeting : meetings) {
            // Set first day of meetings
            previousDay = min(previousDay, meeting[0]);

            // Process start and end of meeting
            dayMap[meeting[0]]++;
            dayMap[meeting[1] + 1]--;
        }

        // Add all days before the first day of meetings
        freeDays += (previousDay - 1);
        for (auto& day : dayMap) {
            int currentDay = day.first;
            // Add current range of days without a meeting
            if (prefixSum == 0) {
                freeDays += currentDay - previousDay;
            }
            prefixSum += day.second;
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;
    }
};


// method-0 : using merge intervals logic
/*
TC : O(n.logn)
SC : O(1) // not considering sorting space
*/
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