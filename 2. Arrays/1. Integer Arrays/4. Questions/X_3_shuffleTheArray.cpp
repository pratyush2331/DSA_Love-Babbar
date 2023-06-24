// 1470. Shuffle the Array
// LeetCode : https://leetcode.com/problems/shuffle-the-array/

/*
TC : O(n)
SC : O(1)
*/

/*
can you do it in inplace ?

Intuition-
since 1 <= nums[i] <= 1000

And we know that using const(any number > 1000, in this case),
we can encode encode num as-
num = (const * a) + b
and we can get a & b from num as-
a = num/const
b = num%const

Approach-
Example:-
we have to convert {a,c,e,g,i|b,d,f,h,j} ---> {a,b,c,d,e|f,g,h,i,j}

step-1: {a,c,e,g,i|b,d,f,h,j}
Encode using num = (const * a) + b for n to 2*n-1 indices of array

step-2: {a,c,e,g,i|(a+b),(c+d),(e+f),(g+h),(i+j)}
Decode a & b as-
a = num/const
b = num%const

step-3: {a,b,c,d,e|f,g,h,i,j}
*/

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k = 1001;
        int i,j;
        
        i = 0;
        for(j = n; j < 2*n; j++) { // TC: O(n)
            nums[j] = (nums[i] * k) + nums[j];
            i++;
        }

        i = 0;
        for(j = n; j < 2*n; j++) { // TC: O(n)
            nums[i] = nums[j]/k;
            nums[i+1] = nums[j]%k;
            i += 2;
        }

        return nums;
    }
};

int main() {
    
    return 0;
}