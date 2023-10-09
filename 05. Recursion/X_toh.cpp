// Tower Of Hanoi
// gfg : https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?page=1&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&difficulty[]=1&difficulty[]=2&curated[]=8&sortBy=submissions

#include<iostream>
using namespace std;

long long toh(int N, int from, int to, int aux) {
    int cnt = 1;
    
    if(N == 1) {
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        return cnt;
    }
    
    cnt += toh(N-1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    cnt += toh(N-1, aux, to, from);
}

int main() {
    
    return 0;
}