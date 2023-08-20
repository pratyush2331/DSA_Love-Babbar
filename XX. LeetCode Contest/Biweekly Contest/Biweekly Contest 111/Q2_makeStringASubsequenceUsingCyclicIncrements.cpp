// 8014. Make String a Subsequence Using Cyclic Increments
// LeetCode : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

#include<iostream>
using namespace std;


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        
        if(n2 > n1)
            return false;
        
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            int diff = (str2[j] - str1[i] + 26) % 26;
            if(diff == 0 || diff == 1) {
                j++;
            }
            i++;
        }
        
        return j == n2;
    }
};


int main() {
    
    return 0;
}