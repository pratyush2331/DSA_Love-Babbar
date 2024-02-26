// Fibonacci Sum
// GFG : https://www.geeksforgeeks.org/problems/fibonacci-sum1423/1


/*
Given a number positive number N, find value of f0 + f1 + f2 + . + fN where fi indicates ith Fibonacci number.
Remember that f0 = 0, f1 = 1, f2 = 1, f3 = 2, f4 = 3, f5 = 5,
Since the answer can be very large, answer modulo 1000000007 should be returned.
*/


#include<bits/stdc++.h>

using namespace std;


// using DP : matrix exponentiation
/*
TC : O(logn)
SC : O(1)
*/

class Solution{
    const long long MOD = 1e9+7;
    
    // function to multiply 2 matrices
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        int sz = 3; // a.size();
        
        vector<vector<long long>> ans(sz, vector<long long>(sz, 0));
        
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                for(int k = 0; k < sz; k++) {
                    ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                }
            }
        }
        
        return ans;
    }
    
    // function to exponentiate
    vector<vector<long long>> matrixExponentiate(vector<vector<long long>>& a, long long n) {
        if(n < 0) {
            cout << "n can'b be less than zero!";
            exit;
        }
        if(n == 0) { // return identity matrix
            int sz = 3; // a.size();
            vector<vector<long long>> ans(sz, vector<long long>(sz, 0));
            ans[0][0] = ans[1][1] = ans[2][2] = 1;
            return ans;
        }
        if(n == 1) { // return the matrix 'a'
            return a;
        }
        
        // binary exponentitation + DP logic
        vector<vector<long long>> temp = matrixExponentiate(a, n/2);
        vector<vector<long long>> ans = matrixMultiply(temp, temp);
        
        if(n&1) { // for odd power
            ans = matrixMultiply(ans, a);
        }
        
        return ans;
    }
    
    public:
    long long int fibSum(long long int n){
        vector<vector<long long>> a(3, vector<long long>(3, 1));
        a[1][0] = a[2][0] = a[2][2] = 0;
        int sz = 3; // a.size();
        
        vector<vector<long long>> ans = matrixExponentiate(a, n);
        // printing the a^n (fibonacci matrix)
        // for(int i = 0; i < sz; i++) {
        //     for(int j = 0; j < sz; j++) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        return ans[0][2];
    }
};


int main() {
    

    return 0;
}