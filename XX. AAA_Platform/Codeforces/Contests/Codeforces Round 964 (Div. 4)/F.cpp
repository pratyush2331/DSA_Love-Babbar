// 

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<long long> fact(MAXN), inv_fact(MAXN);

// Function to compute x^y under modulo m
long long mod_exp(long long x, long long y, long long m) {
    long long result = 1;
    x = x % m;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % m;
        }
        y = y >> 1;
        x = (x * x) % m;
    }
    return result;
}

// Function to precompute factorials and inverse factorials
void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = mod_exp(fact[i], MOD - 2, MOD);
    }
}

// Function to compute combination C(n, k)
long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

// Function to process each test case
void run() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int median_idx = k / 2;
    long long total_sum = 0;

    vector<int> prefix_ones(n + 1, 0), suffix_ones(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_ones[i + 1] = prefix_ones[i] + (a[i] == 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        suffix_ones[i] = suffix_ones[i + 1] + (a[i] == 1);
    }

    for (int i = 0; i < n; ++i) {
        if (i >= median_idx && i + median_idx < n) {
            long long left_count = comb(i, median_idx);
            long long right_count = comb(n - i - 1, median_idx);
            long long count = left_count * right_count % MOD;
            total_sum = (total_sum + count * a[i]) % MOD;
        }
    }

    cout << total_sum << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precompute();
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}