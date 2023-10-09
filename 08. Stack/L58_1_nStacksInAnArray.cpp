// N Stacks In An Array
// CodeStudio : https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

// Method-1 : S/N (stacks) -> BRUTE FORCE

// Method-2 : OPTIMAL CODE
// TC : O(1), SC : O(S + N)
#include <bits/stdc++.h> 
class NStack
{
    int* arr;
    int* top;
    int* next;

    int n, s;

    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->n = N;
        this->s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for(int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // next initialise
        for(int i = 0; i < s; i++) {
            next[i] = i+1;
        }
        // update last index value to -1
        next[s-1] = -1;

        // initialise freeSpot
        freeSpot = 0; // range : 0 to size-1
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freeSpot == -1) {
            return false;
        }

        // step-1: find index
        int index = freeSpot;

        // step-2: update freeSpot
        freeSpot = next[index];

        // step-3: insert element into array
        arr[index] = x;

        // step-4: update next
        next[index] = top[m-1];

        // step-5: update top
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if(top[m-1] == -1) {
            return -1;
        }

        // reverse operation of pop()
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main() {

    return 0;
}