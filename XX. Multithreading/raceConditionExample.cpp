// Race condition example in C++

#include <iostream>
#include <thread>
using namespace std;

int shared_var = 0;

void increment() {
    for (int i = 0; i < 1000000; i++) {
        shared_var++;  // Critical section
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Final value: " << shared_var << endl;
    return 0;
}
