// String In-built functions

#include<iostream>
using namespace std;

int main() {

    // string1.erase(x, y) erase portion of a string
    
    string phone_number;

    cout << "Enter your phone number : ";
    getline(cin, phone_number);

    phone_number.erase(0, 4);

    cout << "phone number : " << phone_number << endl;




    /*
    string first_name;

    cout << "Enter your first name : ";
    getline(cin, first_name);

    string substring;
    cout << "Search for which character/s? : ";
    getline(cin, substring);

    int position = first_name.find(substring);

    cout << "Found character/s at Index : " << position << endl;
    */



    // string1.insert(int x, string2); Insert a string
    /*
    string username;

    cout << "Enter your username : ";
    getline(cin, username);

    username.insert(0, "@");

    cout << "reply : " << username << endl;
    */


    
    // string1.substr(int x, int y) retrieve a portion of a string
    /*
    string first_name;

    cout << "Enter your first name : ";
    getline(cin, first_name);

    string nickname = first_name.substr(0, 3);

    cout << "Your nickname is " << nickname << endl;
    cout << "Hello " << nickname << endl;
    */



    // string1.at(x) returns a character at a given index
    /*
    string first_name;
    string middle_name;
    string last_name;

    cout << "Enter your first name : ";
    getline(cin, first_name);

    cout << "Enter your middle name : ";
    getline(cin, middle_name);

    cout << "Enter your last name : ";
    getline(cin, last_name);

    char letter1 = first_name.at(0);
    char letter2 = middle_name.at(0);
    char letter3 = last_name.at(0);

    cout << "Your initials are : " << letter1 << letter2 << letter3 << endl;
    */



    // string1.append(string2) appends a string
    /*
    string username;

    cout << "Enter your username : ";
    getline(cin, username);

    string email = username.append("@gmail.com");

    cout << "Your email is now : " << email << endl;
    */



    // string.clear() clears a string
    /*
    cout << "Enter your name : ";
    getline(cin, first_name);

    cout << "Welcome " << first_name << endl;

    first_name.clear();

    cout << "*Your name has been cleared*" << endl;

    cout << "Welcome " << first_name << endl;
    */



    // string.empty() return strue if empty
    /*
    cout << "Enter your name : ";
    getline(cin, first_name);

    if(first_name.empty()) {
        cout << "You didn't enter your name >:(" << endl;
    }
    else{
        cout << "Welcome " << first_name << endl;
    }
    */



    // string.length() returns length of a string
    /*
    cout << "Enter your name : ";
    getline(cin, first_name);

    if(first_name.length() > 12) {
        cout << "Your name can't be too long" << endl;
    }
    else{
        cout << "Welcome " << first_name << endl;
    }
    */

    return 0;
}