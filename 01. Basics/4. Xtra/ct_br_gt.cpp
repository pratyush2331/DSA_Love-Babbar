// continue, break and goto statement

#include<iostream>
using namespace std;

// continue;
/*
int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;

    int skip;
    cout << "Enter any number to skip: ";
    cin >> skip;

    for(int i = 1; i <= n; i++) {
        if(i == skip)    // it'll check & skip that num
            continue;
        cout << i << " ";
    }
    return 0;
}
*/

// -------------------------------------------------------------------------------------------------------------------------

// break;
/*
int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;

    int num;
    cout << "Enter any number to break: ";
    cin >> num;

    for(int i = 1; i <= n; i++) {
        if(i == num)    // it'll check & from that num
            break;
        cout << i << " ";
    }
    return 0;
}
*/

// -------------------------------------------------------------------------------------------------------------------------

// goto <label>
/*
int main() {
    int n;
    cout << "Enter any number: ";
    cin >> n;

    if(n % 2 == 0) 
        goto even;
    else
        goto odd;
    
    even: 
    cout << "The number is even!" << endl;
    goto end;
    // return 0;
    
    odd: 
    cout << "The number is odd!" << endl;
    goto end;
    // return 0;
    
    end:
    return 0;
}
*/
/*
int main() {
    int n;
    
    try_again: 
    cout << "Enter number > 10 : ";
    cin >> n;

    if(n <= 10) 
        goto try_again;
    else 
        cout << "Number is > 10" << endl;

    return 0;
}
*/
// /*
int main() {
    int n;
    for(int i = 0; i < 100000; i++) {
        for(int j = 0; j < 100000; j++) {
            cout << "Enter any number, Enter 0 to EXIT : " << endl;
            cin >> n;
            // if(n == 0) break; ---> this will not work here
            if(n == 0) goto end;
        }
    }

    end:
    cout << "Thank You, have a nice day :)" << endl;
    return 0;
}
// */