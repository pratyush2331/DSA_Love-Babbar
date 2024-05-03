// Random Number Generator in c++

/*
int rand(void);
void srand(int); int rand(void)
*/

#include<iostream>
#include<time.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << -10 + rand() % 11 << " \n"; // range : [-10, -10 + 10]
    
    cout << RAND_MAX << " \n";
    
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";

    srand(time(0)); // ver important
    
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";
    cout << rand() << " \n";
    
    return 0;
}