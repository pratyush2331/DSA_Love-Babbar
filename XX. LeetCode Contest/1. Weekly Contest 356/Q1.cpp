// 2798. Number of Employees Who Met the Target
// LeetCode : https://leetcode.com/contest/weekly-contest-356/problems/number-of-employees-who-met-the-target/

// Topic : array/vector

#include<iostream>
using namespace std;


class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for(int i = 0; i < hours.size(); i++) {
            if(hours[i] >= target)
                count++;
        }
        return count;
    }
};


int main() {
    
    return 0;
}