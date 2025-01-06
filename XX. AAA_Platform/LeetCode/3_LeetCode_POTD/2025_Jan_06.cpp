// 1769. Minimum Number of Operations to Move All Balls to Each Box
// LeetCode : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

#include<bits/stdc++.h>
using namespace std;





// Some More Better Solution
/*
TC : O(2n)
SC : O(n)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n);
        int cnt = 0, prev = 0, curr = 0;
        for(int i = 1; i < n; i++) { // TC:O(n)
            if(boxes[i-1] == '1') cnt++;
            ans[i] = prev + cnt;
            prev = ans[i];
        }
        cnt = 0, prev = 0;
        for(int i = n-2; i >= 0; i--) { // TC:O(n)
            if(boxes[i+1] == '1') cnt++;
            int curr = prev + cnt;
            ans[i] += curr;
            prev = curr;
        }
        return ans;
    }
};


// Better Solution
/*
TC : O(3n)
SC : O(2n)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> ans(n);
        vector<int> onePrefix(n, 0), oneSuffix(n, 0); // SC:O(2n)
        int cnt = 0;
        for(int i = 1; i < n; i++) { // TC:O(n)
            if(boxes[i-1] == '1') cnt++;
            onePrefix[i] += onePrefix[i-1] + cnt;
        }
        cnt = 0;
        for(int i = n-2; i >= 0; i--) { // TC:O(n)
            if(boxes[i+1] == '1') cnt++;
            oneSuffix[i] += oneSuffix[i+1] + cnt;
        }

        for(int i = 0; i < n; i++) { // TC:O(n)
            ans[i] = onePrefix[i] + oneSuffix[i];
        }
        return ans;
    }
};


// Brute Force
/*
TC : O(n^2)
SC : O(1)
*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length());
        for(int i = 0; i < boxes.length(); i++) {
            int moves = 0;
            int pos = 1;
            for(int j = i-1; j >= 0; j--) moves += (boxes[j] == '1') * pos++;
            pos = 1;
            for(int j = i+1; j < boxes.length(); j++) moves += (boxes[j] == '1') * pos++;
            ans[i] = moves;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}