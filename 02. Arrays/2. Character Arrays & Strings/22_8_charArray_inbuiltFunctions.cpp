// 

#include<iostream>
#include<cstring>

using namespace std;

int main() {
    char input1[100] = "abcde"; 
    char input2[100] = "xyz";

    cout << "Before copying : " << endl;
    cout << "Input 1 : " << input1 << endl;
    cout << "Input 2 : " << input2 << endl;
    // strcpy(input1, input2);
    // strcpy(input1, "hello");

    strncpy(input1, input2, 2);

    cout << "After copying : " << endl;
    cout << "Input 1 : " << input1 << endl;
    cout << "Input 2 : " << input2 << endl;
    
    // cin >> input1;
    // cin >> input2;

    /*
    if(strcmp(input1, input2) == 0) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    */

    /*
    int len = strlen(input1);
    cout << "Length : " << len << endl;
    */
    return 0;
}