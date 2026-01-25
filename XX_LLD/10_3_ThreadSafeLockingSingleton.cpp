// Thread safe singleton implementation using mutex for locking.
// It’s a performance optimization concern, and not a bug.
// It's not checking if the instance is already created before acquiring the lock.
#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Lock for thread safety
        if (instance == nullptr) {
            instance = new Singleton();
        }
         return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}