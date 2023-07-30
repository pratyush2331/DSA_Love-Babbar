// Next Smaller Element
// CodeStudio : https://www.codingninjas.com/studio/problems/next-smaller-element_1112581

#include<iostream>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n);

    stack<int> s;
    s.push(-1);
    for(int i = n-1; i >= 0; i--) {
        while(s.top() >= arr[i]) {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main() {
    
    return 0;
}
