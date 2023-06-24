// Sum of Two Arrays
// CodeStudio : https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186

/*
Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list i.e. output array/list will also contain only single digit at every index.
Note:
The sizes N and M can be different. 

Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry. 

No need to print the elements of the output array/list.
Using the function "sumOfTwoArrays", write the solution to the problem and store the answer inside this output array/list. The main code will handle the printing of the output on its own.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the required sum of the arrays/list in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec 
Sample Input 1:
1
3
6 2 4
3
7 5 6
Sample Output 1:
1 3 8 0

Sample Input 2:
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9
Sample Output 2:
0 8 6 5
1 0 2 2 0
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(max(n, m)),      SC: O(max(n, m))
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans; // to store answer
    
    int i = n-1, j = m-1;
    int sum = 0, carry = 0;
    while(i >= 0 && j >= 0) {
        sum = a[i--] + b[j--];
        sum += carry;
        ans.push_back(sum % 10);
        carry = sum/10;
    }
    while(i >= 0) {
        sum = a[i--];
        sum += carry;
        ans.push_back(sum % 10);
        carry = sum/10;
    }
    while(j >= 0) {
        sum = b[j--];
        sum += carry;
        ans.push_back(sum % 10);
        carry = sum/10;
    }
 
    if(carry) {
        ans.push_back(carry);
    }
    // else {
    //     ans.push_back(0);      // new question of Coding Ninjas
    // }

    reverse(ans.begin(), ans.end());
    
    return ans;
}

void printArray(vector<int> arr, int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> a, b;

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        a.push_back(data);
    }

    for(int i = 0; i < m; i++) {
        int data;
        cin>>data;
        b.push_back(data);
    }

    vector<int> ans = findArraySum(a, n, b, m);

    int size = ans.size();

    printArray(ans, size);

    return 0;
}