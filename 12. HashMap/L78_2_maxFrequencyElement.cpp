// Maximum Frequency Number
// CodeStudio : https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0

/*
TC : O(n)
SC : O(n)
*/

#include<iostream>
using namespace std;

int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int,int> count; // SC: O(n)

    int maxFreq = 0;
    for(int i = 0; i < n; i++) { // TC: O(n)
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i = 0; i < n; i++) { // TC: O(n)
        if(maxFreq == count[arr[i]])
            return arr[i];
    }
}

int main() {
    
    return 0;
}