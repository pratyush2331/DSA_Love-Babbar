// Check if it is possible to survive on Island
// GFG : https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1

#include<iostream>
using namespace std;


class Solution{
    public:
    int minimumDays(int S, int N, int M){
        // code here
        
        // very imp edge case
        if(N-M == 1 && S >= 7) return -1;

        int sunday = S / 7;
        int buyingDays = S - sunday;
        int totalFood = S * M;
        
        int ans = 0;
        if(totalFood % N == 0)
            ans = totalFood / N;
        else
            ans = (totalFood / N) + 1;
        
        if(ans <= buyingDays)
            return ans;
        else
            return -1;
    }
};


int main() {
    
    return 0;
}