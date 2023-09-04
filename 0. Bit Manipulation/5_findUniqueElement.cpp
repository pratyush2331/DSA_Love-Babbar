// Q. given an array/vector with each number repeating twice except one number. Find that number.
/*
Example : 
I/P : {1, 1, 2, 3, 4, 2, 4}
O/P : 3
*/

#include<iostream>
#include<vector>
using namespace std;

int getUniqueElement(vector<int> arr) {
    int ans = 0;
    for(auto ele : arr) {
        ans ^= ele;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 4, 2, 4};

    cout << getUniqueElement(arr) << endl;
    
    return 0;
}