// **Problem while running this code**

// TechGig : Chantu Bantu

/*
Constraints
1<= T <=10

1<= G <=100000

1<= N <=G

0<= Price of Gift <=10000000
--------------------------------------------------------------------------------------------------------------------------------------
Input Format
The first line of input consists of number of test cases, T

The first line of each test case consists of number of gifts Chantu Bantu have to buy, N

The second line of each test case consists of number of gifts available in the shop, G

The thirds line of each test case consists of G space-separated integers representing the price of G gifts where the first integer represents the price of first gift and so on.
---------------------------------------------------------------------------------------------------------------------------------------
Output Format
For each test case, print the minimum amount of money Chantu Bantu has to pay to buy the N gifts.
---------------------------------------------------------------------------------------------------------------------------------------
Sample TestCase
Input:
2
3
8
50 70 30 100 80 20 150 10
4
6
10 20 32 412 500 11
Output:
60
73

*/

#include<bits/stdc++.h>

#define ll long int

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        ll items;
        cin >> items;

        ll n;
        cin >> n;

        ll arr[1000000];

        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll sum = 0;
        for(ll i = 0; i < items; i++) {
            sum += arr[i];
        }

        cout << sum << endl;
    }

    return 0;
}