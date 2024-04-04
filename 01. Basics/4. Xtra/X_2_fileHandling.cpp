// File Handling in C++

#include<iostream>
#include<fstream> // header file for file handling

using namespace std;

int main() {
    char arr[100];
    cin.getline(arr, 100); // to get i/p until next line is entered/pressed.


    // fstream = ifstream + ofstream

    
    // file write operation
    cout << "File write operation started !" << endl;

    // ofstream obj1("xyz.txt"); // it automatically opens the file, so no need to open the file explicitly
    ofstream obj1("xyz.txt", ios::app); // opens in append mode
    obj1<<arr; // copies arr to myfile object
    obj1.close(); // close the file

    cout << "File write operation performed successfully !" << endl;
    

    // file read operation
    cout << "Reading from file operation started !" << endl;

    ifstream obj2("xyz.txt"); // it automatically opens the file, so no need to open the file explicitly
    char arr1[100]; // to store contents/texts from "xyz" file
    obj2.getline(arr1, 100); // copies obj2 to arr1
    cout << "array contenet : " << arr1 << endl;
    obj2.close(); // close the file

    cout << "Reading from file operation performed successfully !" << endl;
    

    return 0;
}