// 

#include<iostream>
using namespace std;

class A {
    public:
    void fun() {
        cout << "I am A!" << endl;
    }

    private:
    int x = 0;
    string a = "Pratyush";
};

class B {
    public:
    void fun() {
        cout << "I am B!" << endl;
    }

    private:
    int x = 0;
    string a = "Pratyush";
};

class C : public A, public B {

}; 


int main() {
    C obj;

    obj.A::fun();
    obj.B::fun();
    
    return 0;
}