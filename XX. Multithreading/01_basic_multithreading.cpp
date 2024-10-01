#include<iostream>
#include <thread>

using namespace std;

void work() {
    for(int i = 0; i < 10; i++) {
        cout << "Loop " << i << " ";
    }
    cout << "\n";
}

int main() {
    thread t(work);

    return 0;
}