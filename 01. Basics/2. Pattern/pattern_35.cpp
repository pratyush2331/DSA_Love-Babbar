// pattern

/*
for n = 1;
*

for n = 2
 *
***

for n = 3
  *
 * *
*****

for n = 5
    *
   * *
  *   *
 *     *
*********

for n = 10
         *
        * *
       *   *
      *     *
     *       *
    *         *
   *           *
  *             *
 *               *
*******************
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	int i = 1;
	while(i <= n){
		// if(i == 4)
		// space
		int j = n-i;
		while(j >= 1) {
			cout << " ";
			j--;
		}

		cout << "*";
		if(i > 1) {
			int k = 1;
			while(k <= 2*(i-2)+1) {
				if(i == n) {
					cout << "*";
				}
				else {
					cout << " ";
				}
				k++;
			}
			cout << "*";
		}

		cout << endl;
		i++;
	}
	return 0;
}