// 

#include<iostream>
using namespace std;

class Human {
    public:
    int age;
    int weight;
    int height;

    Human() {
        age = 18;
        weight = 60;
        height = 6;
    }

    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;
    }
};

class Male : public Human {
    public:
    string color;

    Male() {
        color = "White";
    }

    void sleep() {
        cout << "Male is sleeping!" << endl;
    }

    int getHeight() {
        return this->height;
    }
};

int main() {
    Male object1;
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;
    cout << object1.color << endl;
    object1.setWeight(84);
    cout << object1.weight << endl;
    object1.sleep();
    
    return 0;
}