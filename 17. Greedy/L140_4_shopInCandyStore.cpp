// Shop in Candy Store
// GFG : https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include<iostream>
using namespace std;


/*
TC : O(n.logn)
SC : O(1)
*/
class Solution {
    public:
    vector<int> candyStore(int candies[], int N, int K) {
        // Write Your Code here
        sort(candies, candies + N); // TC: O(n.logn)
        
        
        int minMoney = 0;
        int buy = 0, free = N-1;
        while(buy <= free) { // TC: O(n)
            minMoney += candies[buy];
            buy++;
            free -= K;
        }
        
        int maxMoney = 0;
        buy = N-1; free = 0;
        while(free <= buy) { // TC: O(n)
            maxMoney += candies[buy];
            buy--;
            free += K;
        }
        
        
        return {minMoney, maxMoney};
    }
};


int main() {
    
    return 0;
}