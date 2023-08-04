// Job Sequencing Problem
// GFG : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1


/*
TC : O(n.logn) + O(n*k)
SC : O(k)
*/

#include<iostream>
using namespace std;

/*
struct Job {
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution {
    // method-2 : disjoint sets


    // method-1 : greedy
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    
    public:
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        sort(arr, arr+n, cmp);
        
        int maxiDeadline = INT_MIN;
        for(int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }
        
        vector<bool> schedule(maxiDeadline+1, true); // '1' based indexing
        int jobCount = 0, maxProfit = 0;
        for(int i = 0; i < n; i++) {
            int currProfit = arr[i].profit;
            int currID = arr[i].id; // no need
            int currDead = arr[i].dead;
            
            for(int k = currDead; k > 0; k--) {
                if(schedule[k]) { // 'k' timeslot empty hai
                    jobCount++;
                    maxProfit += currProfit;
                    schedule[k] = false;
                    // imp
                    break;
                }
            }
        }
        
        return {jobCount, maxProfit};
    }
};


int main() {
    
    return 0;
}