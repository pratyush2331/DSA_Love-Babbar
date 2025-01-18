// 2683. Neighboring Bitwise XOR
// LeetCode : https://leetcode.com/problems/neighboring-bitwise-xor/

#include<bits/stdc++.h>
using namespace std;


// method-2 : one liner
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return !accumulate(derived.begin(), derived.end(), 0, bit_xor<int>());
    }
};


// method-2 : best & optimal (space optimized)
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool ans = 0;
        for(int i = 0; i < derived.size(); i++) {
            ans ^= derived[i];
        }
        return !ans;
    }
};


// method-1 : brute (space optimized)
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool first = 0, second;
        for(int i = 0; i <= n-2; i++) {
            second = first ^ derived[i];
            first = second;
        }
        return derived[n-1] == second ^ 0;
    }
};


// method-0 : brute force
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<bool> original(n, 0);
        for(int i = 0; i <= n-2; i++) {
            original[i+1] = original[i] ^ derived[i];
        }
        return derived[n-1] == original[n-1] ^ original[0];
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}