#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    // TC : O(n), SC : O(n)
    private:
    bool knows(vector<vector<int>>& M, int a,int b) {
        if(M[a][b] == 1) {
            return true;
        }
        return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
        stack<int> s;
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b)) {
                s.push(b);
            }
            else {
                s.push(a);
            }
        }
        
        // s.top() is a potential candidate
        // verify s.top()
        
        int zeroCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[s.top()][i] == 0) {
                zeroCount++;
            }
        }
        if(zeroCount != n) {
            return -1;
        }
        
        int oneCount = 0;
        for(int i = 0; i < n; i++) {
            if(M[i][s.top()] == 1) {
                oneCount++;
            }
        }
        if(oneCount != n-1) {
            return -1;
        }
        
        return s.top();
    }
    
    
    /*
    // BRUTE FORCE, TC : O(n^2), SC : O(1)
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i = 0; i < n; i++) {
            int rowSum = 0;
            for(int j = 0; j < n ;j++) {
                if(M[i][j]) {
                    rowSum++;
                }
            }
            int colSum = 0;
            for(int j = 0; j < n; j++) {
                if(M[j][i]) {
                    colSum++;
                }
            }
            
            if(rowSum == 0 && colSum == n-1) {
                return i;
            }
        }
        
        return -1;
    }
    */
    
};

int main() {

    return 0;
}