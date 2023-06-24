// Class & Objects

#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

    void print() {
        cout << level << endl;
    }



    // Getter

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }



    // Setter

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

};

int main() {

    /*
    Hero h1;
    cout << "size : " << sizeof(h1) << endl;
    */


    // Creation of Object
    Hero ramesh;

    // cout << "size of ramesh : " << sizeof(ramesh) << endl;

    // ramesh.health = 70;

    // setter use
    ramesh.setHealth(70);

    ramesh.level = 'A';

    // cout << "health is : " << ramesh.health << endl;

    // getter use
    cout << "health is : " << ramesh.getHealth() << endl;

    cout << "Level is : " << ramesh.level << endl;
    ramesh.print();
    
    return 0;
}