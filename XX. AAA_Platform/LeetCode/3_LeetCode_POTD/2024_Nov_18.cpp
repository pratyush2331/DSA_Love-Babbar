// 1652. Defuse the Bomb
// LeetCode : https://leetcode.com/problems/defuse-the-bomb/

#include<bits/stdc++.h>
using namespace std;


// Optimal
/*
TC : O(n*k)
SC : O(1)
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n); // not counting as space
        if(k == 0) return ans;

        int s, e;
        if(k>0) s = 1, e = k;
        else s = (n+k)%n, e = n-1;
        int sum = accumulate(code.begin()+s, code.begin()+e+1, 0);

        for(int i = 0; i < n; i++) {
            ans[i] = sum;
            sum -= code[s];
            s = (s+1)%n;
            e = (e+1)%n;
            sum += code[e];
        }
        return ans;
    }
};



// Better
/*
TC : O(n*k)
SC : O(n)
*/
/*
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n); // not counting as space
        if(k == 0) return ans;

        for(int i = 0; i < n; i++) {
            code.emplace_back(code[i]);
        }
        
        int s, e;
        if(k>0) s = 1, e = k;
        else s = n + k, e = n - 1;
        int sum = accumulate(code.begin()+s, code.begin()+e+1, 0);

        for(int i = 0; i < n; i++) {
            ans[i] = sum;
            sum -= code[s++];
            sum += code[++e];
        }
        return ans;
    }
};
*/



// Brute-force
/*
TC : O(n*k)
SC : O(1)
*/
/*
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n); // not counting as space
        if(k == 0) return ans;
        
        for(int i = 0; i < n; i++) {
            if(k > 0) {
                for(int j = 1; j <= k; j++) {
                    ans[i] += code[(i+j+n)%n];
                }
            }
            else {
                for(int j = -1; j >= k; j--) {
                    ans[i] += code[(i+j+n)%n];
                }
            }
        }
        return ans;
    }
};
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}