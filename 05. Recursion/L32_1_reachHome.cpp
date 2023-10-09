// reachHome(src, dest) function ---> pahuch gya

#include<iostream>
using namespace std;

void reachHome(int src, int dest) {
    
    cout << "src = " << src << " and dest = " << dest << endl;
    
    // base case
    if(src == dest) {
        cout << "pahuch gya !" << endl;
        return ;
    }

    // recurrence relation
    reachHome(src+1, dest);
}

int main() {
    int src = 1;
    int dest = 10;

    cout << endl;

    reachHome(src, dest);
    
    return 0;
}