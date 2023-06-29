// Count Ways To Reach The N-th Stairs
// CodeStudio : https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

/*
constraint : step size can be either 1 or 2 only

sample input : 
2   <---   test case
4
5

sample output : 
5
8
*/

#include<iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    // base case
    if(nStairs < 0)
        return 0;
    if(nStairs == 0)
        return 1;
    
    // recurrence relation
    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int nStairs;
        cin >> nStairs;

        cout << countDistinctWays(nStairs) << endl;
    }
    
    return 0;
}