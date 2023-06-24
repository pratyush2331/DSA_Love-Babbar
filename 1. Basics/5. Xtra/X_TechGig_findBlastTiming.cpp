// TechGig : World Army vs Aliens
// Hint : simply add two timings in 224-hour format

/* Read input from STDIN. Print your output to STDOUT*/

/*
Sample TestCase 1
Input:
19 50
02 20

Output:
22 10
*/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    int hh1, hh2;
    int mm1, mm2;

    cin >> hh1 >> mm1;
    cin >> hh2 >> mm2;

    int hh_carry = 0;
    int mm = mm1+mm2;
    if(mm >= 60) {
        mm -= 60;
        hh_carry = 1;
    }

    int hh = hh1+hh2+hh_carry;

    if(hh >= 24) {
        hh -= 24;
    }

    int hh01 = (hh)/10;
    int hh02 = (hh)%10;
    int mm01 = (mm)/10;
    int mm02 = (mm)%10;

    cout << hh01 << hh02 << " " << mm01 << mm02 << endl;
}
