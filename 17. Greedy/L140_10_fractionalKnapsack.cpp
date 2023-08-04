// Fractional Knapsack
// GFG : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


/*
TC : O(n.logn)
SC : O(n)
*/


#include<iostream>
using namespace std;


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    static bool cmp(pair<double,Item> a, pair<double,Item> b) {
        return a.first > b.first;
    }
    
    public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        vector<pair<double,Item>> v;
        for(int i = 0; i < n; i++) {
            double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
            v.push_back({perUnitValue, arr[i]});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        double totalValue = 0;
        for(int i = 0; i < n; i++) {
            if(v[i].second.weight < W) {
                totalValue += v[i].second.value;
                W -= v[i].second.weight;
            }
            else {
                totalValue += W * v[i].first;
                W = 0;
            }
        }
        
        return totalValue;
    }
};


int main() {
    
    return 0;
}