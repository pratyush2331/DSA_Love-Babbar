// 3234. Count the Number of Substrings With Dominant Ones
// LeetCode : https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones

#include<bits/stdc++.h>
using namespace std;

using ll = long long;


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // prefix sum for 1s
        vector<int> prefixOnes(n, 0);
        for (int i = 0; i < n; ++i) {
            prefixOnes[i] = (s[i] == '1' ? 1 : 0);
            if(i-1 >= 0) prefixOnes[i] += prefixOnes[i-1];
        }

        // sub array from i to j
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int ones = prefixOnes[j];
                if(i-1 >= 0) ones -= prefixOnes[i-1];
                int zeros = (j-i+1) - ones;

                if(zeros*zeros > ones) j+= ((zeros*zeros)-ones-1);
                else {
                    ans++;

                    // check for other substring starting from i
                    if(zeros*zeros < ones) {
                        int diff = sqrt(ones) - zeros;
                        int nextj = j + diff;
                        if(nextj >= n) {
                            ans += (n-j-1);
                        }
                        else {
                            ans += diff;
                        }
                        j = nextj;
                    }
                }
            }
        }

        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    return 0;
}