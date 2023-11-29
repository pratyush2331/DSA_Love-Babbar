// Q. Count the number of digits in L to R such that frequency of a particular digit (d) = k.
// Constraint : 0 <= L <= R <= 10^18;    0 < k <= 162;

// #include<iostream>
#include<bits/stdc++.h>

using namespace std;

int k, d;
vector<int> v;
int dp[20][165][2];

int hf(int idx, int freq, int smaller) {
    if(idx == v.size()) {
        return freq == k;
    }

    if(dp[idx][freq][smaller] != -1) {
        return dp[idx][freq][smaller];
    }

    int lim;
    lim = smaller ? 9 : v[idx];

    int cnt = 0;
    for(int i = 0; i <= lim; i++) {
        int new_condn = smaller;
        if(i < lim) new_condn = 1;
        int new_freq = freq;
        if(i == d) new_freq++;
        cnt += hf(idx+1, new_freq, new_condn);
    }

    return dp[idx][freq][smaller] = cnt;
}

int G(int num) {
    while(num) {
        v.push_back(num%10);
        num /= 10;
    }
    reverse(v.begin(), v.end());

    memset(dp, -1, sizeof(dp));
    int temp_ans = hf(0, 0, 0); // (idx, freq, smaller)
    v.clear();
    return temp_ans;
}

int main() {
    int l, r;
    cin >> l >> r >> d >> k;

    int ans = G(r) - G(l-1);
    cout << ans << "\n";

    return 0;
}