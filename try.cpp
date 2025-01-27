// 

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {
    // vector<int> v(10);

    // v[0] = 1;
    // for(int i = 1; i < 10; i++) {
    //     v[i] = v[i-1] + 3;
    // }

    // printArray(v);


    vector<int> v; // size = 0, cap  = 0

    v.push_back(1); // size 1, cap = 1
    for(int i = 1; i < 10; i++) {
        int res = v[i-1] + 3;
        v.push_back(res);
    }

    printArray(v);
    
    return 0;
}