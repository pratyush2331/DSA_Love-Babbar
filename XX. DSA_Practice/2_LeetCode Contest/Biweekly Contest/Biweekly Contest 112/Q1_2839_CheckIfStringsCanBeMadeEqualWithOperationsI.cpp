// 2839. Check if Strings Can be Made Equal With Operations I
// LeetCode : https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/

// Topics : string, unordered_map

#include<iostream>
using namespace std;


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char, int> mp11, mp12, mp21, mp22;
        
        for(int i = 0; i < s1.size(); i++) {
            if(i&1) {
                mp12[s1[i]]++;
                mp22[s2[i]]++;
            }
            else {
                mp11[s1[i]]++;
                mp21[s2[i]]++;
            }
        }
        
        return (mp11 == mp21) && (mp12 == mp22);
    }
};


int main() {
    
    return 0;
}