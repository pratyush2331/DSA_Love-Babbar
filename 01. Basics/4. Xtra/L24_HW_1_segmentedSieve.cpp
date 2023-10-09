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

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N = 1000000;
bool* sieve; // Use a pointer for dynamic allocation

void createSieve() {
    sieve = new bool[N + 1]; // Dynamically allocate the sieve array
    for (int i = 2; i <= N; i++) {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
}

vector<int> greaterPrimes(int N) {
    vector<int> ds;
    for (int i = 2; i <= N; i++) {
        if (sieve[i] == true) {
            ds.push_back(i);
        }
    }
    return ds;
}

int main() {
    createSieve();

    int l, r;
    cout << "Enter lower & upper limit : ";
    cin >> l >> r;

    // Ensure the range is valid for segmented sieve
    if (l < 2)
        l = 2;
    if (r - l > N)
        r = l + N;

    // Step 1: Generate all primes till sqrt(r)
    vector<int> primes = greaterPrimes(sqrt(r));

    // Step 2: Create a dummy array of size = r - l + 1 and make everyone as 1
    int dummy[r - l + 1];
    for (int i = 0; i < r - l + 1; i++) {
        dummy[i] = 1;
    }

    // Step 3: For all prime numbers mark their multiples as false
    for (auto pr : primes) {
        int firstMultiple = (l / pr) * pr;
        if (firstMultiple < l)
            firstMultiple += pr;

        for (int j = max(firstMultiple, pr * pr); j <= r; j += pr) {
            dummy[j - l] = 0;
        }
    }

    // Step 4: Get all the primes and print them
    for (int i = l; i <= r; i++) {
        if (dummy[i - l]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Remember to deallocate the dynamically allocated memory before exiting
    delete[] sieve;

    return 0;
}
