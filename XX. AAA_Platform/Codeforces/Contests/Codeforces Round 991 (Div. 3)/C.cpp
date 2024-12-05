// // 

// #include<iostream>
// using namespace std;

// using ll = long long;

// void run() {
//     string n;
//     cin >> n;
//     // cout << n << " ";

//     int cnt2 = 0, cnt3 = 0;
//     ll sum = 0LL;
//     for(int i = 0; i < n.length(); i++) {
//         int digit = n[i] - '0';
        
//         if(digit == 2) cnt2++;
//         if(digit == 3) cnt3++;

//         sum += digit;
//     }

//     if(sum%9 == 0) {
//         cout << "YES\n";
//         return;
//     }

//     int rem = sum;
//     cout << left << " ";

//     if(left&1) {
//         cout << "NO\n";
//         return;
//     }

//     // cout << cnt2 << " : " << cnt3 << " : " << left << " ";

//     while(cnt3 && left >= 6) {
//         left -= 6;
//         cnt3--;
//     }
//     while(cnt2 && left >= 2) {
//         left -= 2;
//         cnt2--;
//     }

//     if(left == 0) cout << "YES\n";
//     else cout << "NO\n";
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     int t = 1;
//     cin >> t;
//     while(t--) run();
    
//     return 0;
// }