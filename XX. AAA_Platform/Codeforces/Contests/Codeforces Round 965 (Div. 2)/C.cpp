// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        
        sort(ord.begin(), ord.end(), [&](int i, int j) {
            return a[i] > a[j];
        });

        int need = ((n - 1) >> 1) + 1;
        int64_t low = 0, high = 1e10;
        while (low < high) {
            int64_t mid = (low + high + 1) >> 1;
            bool ok = false;
            for (int i : ord) {
                if (b[i] == 1) {
                    if (a[i] + k >= mid) ok = true;
                    int64_t x = mid - a[i] - k;
                    int rem = need;
                    for (int j : ord) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) rem--;
                    }
                    if (rem == 0) ok = true;
                    break;
                }
            }
            for (int i : ord) {
                if (b[i] == 0) {
                    int64_t rem = need;
                    int64_t sum = 0;
                    int64_t x = mid - a[i];
                    for (int j : ord) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) {
                            rem--;
                        } else if (b[j]) {
                            sum += x - a[j];
                            rem--;
                        }
                    }
                    if (rem == 0 && sum <= k) {
                        ok = true;
                    }
                    break;
                }
            }
            if (ok) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        cout << low << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    run();
        
    return 0;
}