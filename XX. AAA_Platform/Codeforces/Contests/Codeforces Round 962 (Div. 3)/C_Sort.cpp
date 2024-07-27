 #include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> prefixA(n + 1, vector<int>(26, 0));
    vector<vector<int>> prefixB(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            prefixA[i + 1][j] = prefixA[i][j];
            prefixB[i + 1][j] = prefixB[i][j];
        }
        prefixA[i + 1][a[i] - 'a']++;
        prefixB[i + 1][b[i] - 'a']++;
    }

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    for (int i = 0; i < q; i++) {
        int l = queries[i][0];
        int r = queries[i][1];

        int ans = 0;
        for (int j = 0; j < 26; ++j) {
            int countA = prefixA[r][j] - prefixA[l - 1][j];
            int countB = prefixB[r][j] - prefixB[l - 1][j];
            if (countB > countA) {
                ans += (countB - countA);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}
