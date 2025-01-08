// 3042. Count Prefix and Suffix Pairs I
// LeetCode : https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    bool isPrefixAndSuffix(string& str1, string& str2) {
        int n1 = str1.length(), n2 = str2.length();
        bool prefixMatched = 1, suffixMatched = 1;

        for (int i = 0; i < n1; i++) {
            // Check prefix condition
            if (i >= n2 || str1[i] != str2[i]) {
                return 0;
            }
            // Check suffix condition
            if (n1 - 1 - i >= 0 && n2 - 1 - i >= 0 && str1[n1 - 1 - i] != str2[n2 - 1 - i]) {
                return 0;
            }
        }
        return 1;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
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