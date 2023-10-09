// 

#include<iostream>
using namespace std;

void update(int **ptr) {
    ptr = ptr + 1;
    // kuch change hoga - NO

    // *ptr = *ptr + 1;
    // kuch change hoga - YES
    
    // **ptr = **ptr + 1;
    // kuch change hoga - YES

}

int main() {
    int i = 5;
    int *p1 = &i;
    int **p2 = & p1;

    // /*
    cout << endl << "Sab shi chal rha h !" << endl << endl;

    cout << "printing i    : " << i << endl;
    cout << "printing *p1  : " << *p1 << endl;
    cout << "printing **p2 : " << **p2 << endl;
    cout << endl;

    cout << "address of i  : " << &i << endl;
    cout << "printing p1   : " << p1 << endl;
    cout << "printing *p2  : " << *p2 << endl;
    cout << endl;

    cout << "address of p1 : " << &p1 << endl;
    cout << "printing p2   : " << p2 << endl;
    cout << endl;

    cout << "address of p2 : " << &p2 << endl;
    // */

    /*
    cout << endl << endl;
    cout << "before : " << i << endl;
    cout << "before : " << p1 << endl;
    cout << "before : " << p2 << endl;
    update(p2);
    cout << "after  : " << i << endl;
    cout << "after  : " << p1 << endl;
    cout << "after  : " << p2 << endl;
    */
    
    return 0;
}