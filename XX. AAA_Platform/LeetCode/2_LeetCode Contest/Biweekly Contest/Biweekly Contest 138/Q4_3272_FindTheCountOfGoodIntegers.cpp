// 3272. Find the Count of Good Integers
// LeetCode : https://leetcode.com/problems/find-the-count-of-good-integers/

#include<bits/stdc++.h>
using namespace std;


#define ll long long
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        ll cnt = 0;

        // factorial precomputation
        vector<ll> fact(11, 1);
        for(ll i = 2; i <= 10; i++) {
            fact[i] = i * fact[i-1];
        }

        // computing start and end
        ll start, end;;
        if(n&1) { // odd
            start = pow(10, n/2);
            end = pow(10, n/2 + 1);
        }
        else { // even
            start = pow(10, n/2 - 1);
            end = pow(10, n/2);
        }

        set<string> st; // to search and store unique elements
        for(ll i = start; i < end; i++) {
            string s = to_string(i);
            string p = s;
            if(n&1) s.pop_back();
            reverse(s.begin(), s.end());
            p += s;

            // is palindrome
            string p_rev = p;
            reverse(p_rev.begin(), p_rev.end());
            if(p != p_rev) continue;

            // is diviisble by k
            ll num = stoll(p);
            if(num % k != 0) continue;

            // inserting in set, so that again redundant can't be added
            s = p;
            sort(s.begin(), s.end());
            if(st.find(s) != st.end()) continue;
            st.insert(s);

            // PnC
            unordered_map<char, ll> mp;
            for(auto ch : p) mp[ch]++;
            // first element should not be 0 * ( kuch bhi -> fact[n - 1])
            ll numOfZeros = mp['0'];
            ll ans = (n-numOfZeros) * fact[n-1];
            // Divide for duplicate elements
            for(auto it : mp) ans /= fact[it.second];
            cnt += ans;
        }

        return cnt;
    }
};


int main() {
    
    return 0;
}