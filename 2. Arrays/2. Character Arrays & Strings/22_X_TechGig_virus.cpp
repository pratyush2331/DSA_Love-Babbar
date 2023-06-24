// TechGig (Code-Gladiators-2021) : Problem-1

/*
Input :
coronavius
3
abcde
cronas
coronaous

Output : 
NEGATIVE
POSITIVE
NEGATIVE
*/

#include<iostream>
using namespace std;

bool checkVirus(string str1, string str2) {
    int i = 0, j = 0;
    int count = 0;
    while(i < str2.length() && j < str1.length()) {
        if(str2[i] == str1[j]){
            count++;
            i++;
        }
        else {
            j++;
        }
    }
    if(count == str2.length()) return 1;
    return 0;
}

int main() {

    string str1;
    cin >> str1;

    int n;
    cin >> n;

    while(n--) {
        string str2;

        cin >> str2;

        if(checkVirus(str1, str2)) {
            cout << "POSITIVE" << endl;
        }
        else {
            cout << "NEGATIVE" << endl;
        }
    }
    
    return 0;
}