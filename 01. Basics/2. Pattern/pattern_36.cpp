// Triangle Pattern
// Nxtwave OA (easy) -> for Technical Curriculum  Developer Intern

/*
i/p - 1:
4

o/p - 1:
      *
    * *
  *   *
* * * * 
  *   *
    * *
      *


i/p - 2:
5

o/p - 2:
        *
      * *
    *   *
  *     *
* * * * *
  *     *
    *   *
      * *
        *
*/

#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // taking i/p
    int n;
    cin >> n;
    
    // task
    // starting pattern
    int i = n-1;
    int cnt = 0;
    while(i >= 1) {
        // for space
        int j = 2*i;
        while(j >= 1) {
            cout << " ";
            j--;
        }
        // for star and space
        for(int k = 1; k <= 2*cnt+1; k++) {
            if(k == 1 && cnt != 0) cout << "*";
            else if(k == 2*cnt+1) cout << "*";
            else cout << " ";
        }
        cout << "\n";
        i--;
        cnt++;
    }

    // middle pattern
    i = n;
    while(i--) {
        cout << "* ";
    }
    cout << "\n";

    // last pattern
    i = 1;
    cnt = n-2;
    while(i <= n-1) {
        // for space
        int j = 1;
        while(j <= 2*i) {
            cout << " ";
            j++;
        }
        // for star and space
        for(int k = 2*cnt+1; k >= 1; k--) {
            if(k == 1 && cnt != n-1) cout << "*";
            else if(k == 2*cnt+1) cout << "*";
            else cout << " ";
        }
        cout << "\n";
        i++;
        cnt--;
    }
    
    return 0;
}