// global function as friend

#include<iostream>
using namespace std;

class WithFriend {
    int i;

    public:
    friend void fun(); // global function as friend
};

void fun() {
    WithFriend wf;
    wf.i = 10;  // access to private data member
    cout << wf.i << endl;
}

int main() {

    fun(); //Can be called directly
    
    return 0;
}