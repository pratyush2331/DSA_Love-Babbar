// Power Set
// GFG : https://www.geeksforgeeks.org/problems/power-set4302/1

#include<bits/stdc++.h>

using namespace std;


class Solution{
	public:
	// method-1 : using bit-manipulation
	/*
    TC : O(n.2^n)
    SC : O(1);
    */
    // /*
    vector<string> AllPossibleStrings(string s){
        vector<string> ans;
        
        int n = 1<<s.length(); // n = 2^s.length()
        for(int i = 1; i < n; i++) {
            int x = i;
            string str = "";
            int idx = 0;
            
            while(x) {
                if(x&1) str += s[idx];
                idx++;
                x = x>>1;
            }
            ans.push_back(str);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    // */
    
    
    
    // method-0 : using recursion
    /*
    TC : O(n.2^n)
    SC : O(n) // recursive call stack space
    */
    /*
    void solve(string& s, int i, string str, vector<string>& ans) {
        if(i < 0) {
            if(str.size())
                ans.push_back(str);
            return;
        }
        
        // not-take
        solve(s, i-1, str, ans);
        
        // take
        solve(s, i-1, s[i] + str, ans);
    }
    
    vector<string> AllPossibleStrings(string s){
        vector<string> ans;
        
        solve(s, s.length()-1 ,"", ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    */
};


int main() {
    

    return 0;
}