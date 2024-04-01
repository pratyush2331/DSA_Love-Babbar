
// TechGig : Code-Gladiators (Semi-Final) 2022
// Q1 -> Exam Center (Find Room Number)

/*
2, 14 nhi hona chahiye

constraint:
1 <= N <= 1300
*/

#include<iostream>
using namespace std;

int getRoomNo(int N) {
    int ans = 0;
    int count = 0;
    for(int i = 1; i <= 1300; i++) {
        int temp = i;
        bool flag = 0;
        while(temp) {
            int digit = temp % 10;

            if(digit == 2) {
                flag = 1;
                break;
            }

            if(digit == 4) {
                int t = temp/10;
                if(t%10 == 1) {
                    flag = 1;
                    break;
                }
            }

            temp /= 10;
        }
        if(flag == 0) 
            count++;
        if(count == N) {
            ans = i;
            break;
        }

    }

    return ans;
}

int main() {
    int N;
    cin >> N;

    cout << getRoomNo(N) << endl;
    
    return 0;
}