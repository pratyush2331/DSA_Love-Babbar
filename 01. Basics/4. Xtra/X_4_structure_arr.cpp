// structure basics

#include<bits/stdc++.h>

using namespace std;

struct Person {
    char name[100];
    int age;
    double salary;
};

int main() {
    Person p[2]; // array of structure
    cout << "Enter 2 person details like name, age and salary" << endl;

    for(int i = 0; i < 2; i++) {
        cout << "Enter details of person " << (i+1) << endl;
        cin >> p[i].name;
        cin >> p[i].age;
        cin >> p[i].salary;
    }

    cout << "Details of users" << endl;
    for(int i = 0; i < 2; i++) {
        cout << "Deatils of person " << (i+1) << endl;
        cout << "name: " << p[i].name << endl;
        cout << "age: " << p[i].age << endl;
        cout << "salary: " << p[i].salary << endl;
    }

    return 0;
}