// 75. Sort Colors [OR] Sort 012
// Leetcode : https://leetcode.com/problems/sort-colors/

/*
Input:
6
2 1 2 0 1 0

Output:
Before Sorting: 2 1 2 0 1 0 

After Sorting : 0 0 1 1 2 2  
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Method-1: 3-pointer approach || Dutch National Flag Algorithm
/*
TC : O(n)
SC : O(1)

ALGORITHM (Dutch National Flag):
[0, low-1] --> all 0s
[low, mid-1] --> all 1s
[mid, high] --> unprocessed
[high+1, n-1] --> all 2s
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high) { // TC : O(n)
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Method-2: Counting Sort
// TC : O(n)
/*
void sort012(int arr[], int size)
{
    int c0=0, c1=0, c2=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == 0)
        {
            c0++;
        }
        else if(arr[i] == 1)
        {
            c1++;
        }
        else 
        {
            c2++;
        }
    }
    int i = 0;
    while(c0)
    {
        arr[i] = 0;
        i++;
        c0--;
    }
    while(c1)
    {
        arr[i] = 1;
        i++;
        c1--;
    }
    while(c2)
    {
        arr[i] = 2;
        i++;
        c2--;
    }
}
*/

int main(){
    int arr[20];

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<endl<<"Before Sorting: ";
    printArray(arr, n);
    cout<<endl;
    sort012(arr, n);
    cout<<"After Sorting : ";
    printArray(arr, n);
    return 0;
}