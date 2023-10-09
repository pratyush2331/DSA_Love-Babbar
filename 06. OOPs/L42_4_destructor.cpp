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
    static int timeToComplete;

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

    static int random() {
        return timeToComplete ;
    }

    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }

};

int Hero::timeToComplete = 5;

int main() {

    /*
    // Static
    Hero a;

    // Dynamic
    Hero *b = new Hero();
    // manually destructor call
    delete b;
    */

    cout << Hero::timeToComplete << endl;

    // NOT RECOMENDED
    // Hero a;
    // cout << a.timeToComplete << endl;

    cout << Hero::random() << endl;
    
    return 0;
}