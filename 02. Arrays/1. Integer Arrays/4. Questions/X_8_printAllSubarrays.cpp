// 

#include<bits/stdc++.h>

using namespace std;

void generateSubArrays(vector<int>& nums) {
    int n = nums.size();
    for(int s = 0; s < n; s++) {
        for(int e = s; e < n; e++) {
            for(int i = s; i <= e; i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    generateSubArrays(nums);

    return 0;
}