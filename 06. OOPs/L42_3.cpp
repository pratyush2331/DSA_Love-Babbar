// 

#include<iostream>
#include<string.h>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char *name;
    char level = 'Z';

    // Deafult COnstructor
    Hero() {
        cout << "Simple Constructor Called" << endl;
        name = new char[100];
    }

    // Parametrised Constructor - 1 argument
    Hero(int health) {
        // cout << "this -> : " << this << endl;
        this -> health = health;
    }
    
    // Parametrised Constructor - 2 arguments
    Hero(int health, char level) {
        // cout << "this -> : " << this << endl;
        this -> health = health;
        this -> level = level;
    }

    // Copy Constructor
    Hero(Hero &temp) {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << endl << "Copy Constructor called" << endl << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }
    
    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    // static int random() {
    //     return timeToComplete ;
    // }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

    // print function
    void print() {
        cout << "[ name: " << this->name << ", health: " << this->health << ", level: " << this->level << " ]" << endl;
    }

};

int main() {

    /*

    // static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is : " << a.level << endl;
    cout << "health is : " << a.getHealth() << endl;

    // dynamically
    Hero *b = new Hero;
    b->setHealth(70);
    b->setLevel('A');
    cout << "level is : " << (*b).level << endl;
    cout << "health is : " << (*b).getHealth() << endl;

    cout << "level is : " << b->level << endl;
    cout << "health is : " << b->getHealth() << endl;

    */

    /*
    // Static allocation
    cout << "Hi" << endl;
    Hero ramesh(10);
    cout << "Hello" << endl;
    ramesh.print();
    // cout << "Adderss of Ramesh : " << &ramesh << endl;

    // Dynamically
    cout << "Hi" << endl;
    Hero *h = new Hero(11);
    cout << "Hello" << endl;
    h->print();
   
    // Dynamically
    cout << "Hi" << endl;
    Hero *temp = new Hero(11, 'C');
    cout << "Hello" << endl;
    temp->print();
    */

    /*
    // parametraized constructor called
    Hero S(70, 'C');
    S.print();

    // Copy Constructor called
    Hero R(S);
    R.print();
    */

    
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    // hero1.print();

    // use default copy constructor

    hero1.print();

    Hero hero2(hero1);
    // Hero hero2 = hero1;
    hero2.print();
    hero1.name[0] = 'G';
    hero1.print();

    // hero2.print();

    hero1 = hero2;

    hero1.print();

    hero2.print();
    
    return 0;
}