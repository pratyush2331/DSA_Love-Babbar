// Vector C++

#include<bits/stdc++.h>
using namespace std;

vector<int> randomfunc() {
    vector<int> arr = {1, 2 ,3};
    // arr[0] = 12;
    return arr;
}

int main(){
    vector<int> arrby4;
    arrby4 = randomfunc();
    // for(int i = 0; i < arrby4.size(); i++) {
    //     cout<<arrby4[i]<<" ";
    // }

    for (auto it = arrby4.begin(); it != arrby4.end(); it++)
        cout << *it << " ";

    return 0;
}