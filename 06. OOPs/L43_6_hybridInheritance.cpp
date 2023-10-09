#include<iostream>
using namespace std;

class A {
    public:
    int age = 20;

    void printAge() {
        cout << age << endl;
    }
};

class D {
    public:
    int salary = 10000000;

    void printSalary() {
        cout << salary << endl;
    }
};

class B : public A {
    public:
    int height = 6;

    void printHeight() {
        cout << height << endl;
    }
};

class C : public A, public D {
    public:
    int weight = 60;

    void printweight() {
        cout << weight << endl;
    }
};

int main() {
    C obj;

    obj.printweight();
    obj.printAge();
    obj.printSalary();
    
    return 0;
}