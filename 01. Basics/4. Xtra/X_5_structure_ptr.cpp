// pointer to structure

#include<bits/stdc++.h>

using namespace std;

struct Person {
    char name[100];
    int age;
    double salary;
};

int main() {
    Person p1;

    Person *ptr = &p1;

    cout << "Person deails" << endl << "Enter Person Name:" << endl;
    cin.getline(ptr->name, 100);
    cout << "Enter age" << endl;
    cin >> ptr->age;
    cout << endl << "Enter salary" << endl;
    cin >> ptr->salary;

    cout << endl << "Person details are as follows:" << endl;
    cout << "Person name:" << ptr->name << endl;
    cout << "Person age:" << ptr->age << endl;
    cout << "Person salary:" << ptr->salary << endl;

    return 0;
}