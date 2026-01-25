// Eager Initialization (Thread-Safe)
// In this approach, the singleton instance is created at the time of class loading.
// This ensures that the instance is available when needed and is inherently thread-safe.
// However, it may lead to resource wastage if the instance is never used.
// That's why we should use this approach only when we are sure that the instance will be used in the application, 
// or for lightweight objects.
#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}