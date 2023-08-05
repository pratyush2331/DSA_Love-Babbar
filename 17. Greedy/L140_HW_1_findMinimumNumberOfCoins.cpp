// Greedy Algorithm to find Minimum number of Coins [INDIAN CURRENCY SYSTEM]
// GFG [article] : https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/


/*********************************************************************************************************************
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in 
Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, 
what is the minimum number of coins and/or notes needed to make the change.
*********************************************************************************************************************/


#include<iostream>
#include<algorithm>
using namespace std;

int minCoins(int coins[], int n, int target) {
    sort(coins, coins + n, greater<int>());
    
    int coinCount = 0;
    for(int i = 0; i < n; i++) {
        if(target >= coins[i]) {
            coinCount += (target/coins[i]);
            target %= coins[i];
        }
    }
    
    if(target == 0)
        return coinCount;
    else
        return -1;
}

int main() {
    int target;
    cin >> target;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);

    cout << minCoins(coins, n, target) << endl;
    
    return 0;
}