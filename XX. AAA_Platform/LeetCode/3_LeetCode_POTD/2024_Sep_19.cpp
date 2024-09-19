// 241. Different Ways to Add Parentheses
// LeetCode : https://leetcode.com/problems/different-ways-to-add-parentheses/

#include<bits/stdc++.h>
using namespace std;


// using Recursion
/*
TC : O(n . 2^n)
SC : O(2^n)
*/
class Solution {
    vector<int> solve(string& expression, int s, int e) {
        vector<int> ans;
        for(int i = s; i <= e; i++) {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = solve(expression, s, i-1);
                vector<int> right = solve(expression, i+1, e);
                for(auto x : left) {
                    for(auto y : right) {
                        if(expression[i] == '+') ans.push_back(x+y);
                        else if(expression[i] == '-') ans.push_back(x-y);
                        else if(expression[i] == '*') ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()) ans = {stoi(expression.substr(s, e-s+1))};
        return ans;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size()-1);
    }
};


int main() {

    return 0;
}