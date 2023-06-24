// TechGig (Code-gladiators-2021) Q-2: Prime Game

/* if no prime is present b/w a & b   ---->   return -1, 
   else                               ---->   return primeDifference;
*/

/*
i/p : 
1
2 5
o/p : 
3

i/p : 
1
2 6
3

i/p : 
1
6 8
o/p : 
0

i/p : 
1
8 10
o/p : 
-1
*/

#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
// TC : O(n * log(logn))
// /*
int primeDifference(int a, int n) {
    vector<bool> prime(n+1, 1);

    prime[0] = prime[1] = 0;

    int lowestPrime = 0, highestPrime = -1;
    int count = 0;
    for(int i = 2; i <= n; i++) {
        if(prime[i]) {
            if(i >= a) {
                count++;
                // cout << count << endl;
                highestPrime = i;
                if(count == 1) 
                    lowestPrime = i;
            }
            for(int j = i*i; j <= n; j = j+i) {
                prime[j] = 0;
            }
        }
    }
    // cout << lowestPrime << " " << highestPrime << endl;
    return highestPrime - lowestPrime;
}
// */

// TC : O(n^2)
/*
bool isPrime(int n) {
    if(n < 2) return 0;

    for(int i = 2; i < n; i++) {
        if(n%i == 0) return 0;
    }
    return 1;
}

int primeDifference(int a, int b) {
    int count = 0; // for storing the lowestPrime
    int lowestPrime = 0, highestPrime = -1;
    for(int i = a; i <= b; i++) {
        if(isPrime(i)) {
            highestPrime = i;
            count++;
        }
        if(count == 1) {
            lowestPrime = i;
            count++; // increasing count, so that, it will not change count in future
        }
    }
    return highestPrime - lowestPrime;
}
*/

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        cout << primeDifference(a, b) << endl;
    }
    
    return 0;
}