// 

#include<iostream>
using namespace std;

void run() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if(m <= 0) continue;

        for(int i = 0; i < str.length(); i++) {
            m--;
        }
        if(m >= 0) cnt++;
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}