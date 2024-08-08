// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> suneet = {a1, a2};
    vector<int> slavic = {b1, b2};

    int wins = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int s1 = suneet[i];
            int s2 = suneet[1 - i];
            int v1 = slavic[j];
            int v2 = slavic[1 - j];

            int suneetWins = 0, slavicWins = 0;

            if (s1 > v1) suneetWins++;
            else if (s1 < v1) slavicWins++;

            if (s2 > v2) suneetWins++;
            else if (s2 < v2) slavicWins++;

            if (suneetWins > slavicWins) wins++;
        }
    }

    cout << wins << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}