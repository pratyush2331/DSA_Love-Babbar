// Class & Objects Example

#include<iostream>
using namespace std;

/*
class Car {
    string name;
    int topSpeed;

    void func(string carName, int speed) {
        name = carName;
        topSpeed = speed;
    }
};
*/

/*
class Student {
    int rollno;
    char name[20];
    float marks;
    char grade;

    public:

    int getRollno() {
        return rollno;
    }

    int getMarks() {
        return marks;
    }
    void setGrade() {
        if(marks > 90) grade = 'A';
        else if(marks > 80) grade = 'B';
        else if(marks > 70) grade = 'C';
        else if(marks > 60) grade = 'D';
        else grade = 'E';
    }
};
*/

class Box {
    public:

    double height;
    double width;
    double depth;
};

int main() {
    // Creating an object of Box class
    Box obj;
    // assign values to obj instance variable
    obj.height = 10;
    obj.width = 5;
    obj.depth = 15;
    // Compute the volume of the Box
    double volume = obj.height * obj.width * obj.depth;
    // printing the volume
    cout << "volume of a Box : " << volume;
    return 0;
}