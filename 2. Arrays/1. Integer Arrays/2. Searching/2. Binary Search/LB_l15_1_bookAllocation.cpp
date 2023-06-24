// Allocate Books
// InterviewBit : https://www.interviewbit.com/problems/allocate-books/
// CodeStudio : https://www.codingninjas.com/codestudio/problems/allocate-books_1090540

/* -----------------------------------------------PROBLEM STATEMENT---------------------------------------------------
Given an array of integers A of size N and an integer B.

The College library has N books. The ith book has A[i] number of pages.

You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

    1. A book will be allocated to exactly one student.
    2. Each student has to be allocated at least one book.
    3. Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.
---------------------------------------------------------------------------------------------------------------------- */

/*
Example Input
Input 1:
A = [12, 34, 67, 90]
B = 2
Input 2:
A = [5, 17, 100, 11]
B = 4

Example Output
Output 1:
113
Output 2:
100

Example Explanation
Explanation 1:
There are two students. Books can be distributed in following fashion : 
1)  [12] and [34, 67, 90]
    Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
2)  [12, 34] and [67, 90]
    Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
3)  [12, 34, 67] and [90]
    Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
    Of the 3 cases, Option 3 has the minimum pages = 113.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> A, int n, int B, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i < n; i++) {
        if(pageSum + A[i] <= mid) {
            pageSum += A[i];
        }
        else {
            studentCount++;
            if(studentCount > B || A[i] > mid) return false;
            pageSum = A[i];
        }
    }
    return true;
}

int books(vector<int>& A, int B) {
    int n = A.size();
    
    if(n < B) return -1; // check if (noOfBooks < noOfStudents) and return -1
    
    int s = 0;
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
    }
    
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(A, n, B, mid)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    vector<int> A;
    int n, B;
    cin>>n>>B;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        A.push_back(data);
    }

    cout<<books(A, B)<<endl;
    
    return 0;
}