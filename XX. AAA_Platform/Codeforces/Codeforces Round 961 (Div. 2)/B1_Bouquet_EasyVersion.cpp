#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll sum = 0, ans = 0;
        int start = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
            while(sum > m || (start < n && a[i] - a[start] > 1)) {
                sum -= a[start];
                start++;
            }
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }

    return 0;
}