// not working
// Segmented Sieve
// why to use over sieve? : because size of array can not be greater than 10^8
/*
t -> test case
L, R -> lower bound & upper bound of interval

constraints:
1 <= L <= U <= 10^9
R - L <= 10^6
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> prime;

void sieve(int n) {
    vector<bool>isPrime(n+1, 1);

    isPrime[0] = 0;
    isPrime[1] = 0;

    for(long long i = 2; i <= n; i++) {
        if(isPrime[i]) {
            prime.push_back(i);
            for(long long j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void segSieve(int L, int R) {
    long long sq = sqrt(R);
    sieve(sq);
    vector<bool> Primes(R-L+1, 1);
    for(long long p : prime) {
        long long sm = (L/p)*p;
        if(sm < L)
            sm += p;
        for(long long m = sm; m <= R; m += p) {
            Primes[m-L] = 0;
        }
    }
    int count = 0;
    for(long long i = L; i <= R; i++) {
        if(Primes[i-L] == true) {
            count++;
            cout << i << " ";
        }
    }
    cout << "count = " << count << endl;
}

int main() {
    long long L, R;
    cout << "Enter lower & upper limit : ";
    cin >> L >> R;

    segSieve(L, R);
    
    return 0;
}