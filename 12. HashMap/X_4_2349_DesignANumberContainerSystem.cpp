// 2349. Design a Number Container System
// LeetCode : https://leetcode.com/problems/design-a-number-container-system/

#include<bits/stdc++.h>
using namespace std;


// approach : used 2 HashMaps
/*
change() --> TC : O(logn)
find() --> TC : O(1)
SC : O(2n)
*/
class NumberContainers { // SC:O(n)
    unordered_map<int, int> idx_num; // {idx, num}
    unordered_map<int, set<int>> num_idx; // {num, idx[]}

public:
    NumberContainers() {}
    
    void change(int index, int number) { // TC:O(logn)
        if(idx_num[index]) {
            num_idx[idx_num[index]].erase(index);
            if(num_idx[idx_num[index]].empty()) num_idx.erase(idx_num[index]);
        }
        idx_num[index] = number;
        num_idx[number].insert(index);
    }
    
    int find(int number) { // TC:O(1)
        return num_idx[number].empty() ? -1 : *num_idx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */


int main() {
    
    return 0;
}