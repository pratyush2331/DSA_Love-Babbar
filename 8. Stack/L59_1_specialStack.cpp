// Special Stack : Design a stack that supports getMin() in O(1) time and O(1) extra space
// CodeStudio : https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<iostream>
#include<stack>

using namespace std;

class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
    
    void push(int data) {
        // for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else { // not a first element
            if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        // when stack is empty
        if(s.empty()) {
            return -1;
        }

        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else {
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMini;
        }
    }

    int top() {
        if(s.empty()) {
            return -1;
        }

        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }
        
        return mini;
    }
};

int main() {
    
    return 0;
}