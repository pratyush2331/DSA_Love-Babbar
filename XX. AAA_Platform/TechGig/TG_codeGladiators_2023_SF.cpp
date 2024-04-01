// Techgig Code Gladiators

// Question - 1 : 

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[n];
	int queries[m];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> queries[i];
	}

	for(int i = 0; i < m; i++) {
		int cost = 0;
		for(int j = 0; j < m; j++) {
			cost += abs(queries[i] - arr[j]);
		}
		cout << cost << " ";
	}

	return 0;
}

// Question 2 : Forest Fire (100 Marks)

/*
You are camping in a forest area at night. You are living with the forest officers to experience their challenges and hardships to create a documentary on them. Everything was going well. Suddenly, a fire has broken out in the forest and it is expanding exponentially. There is a lot of chaos and cries of animals. It is going to take alot of time for the backup. Some of the posts in the forest have also caught fire. The officers are trying everything to safeguard the animals but the fire is spreading too fast. Amid such chaos, the petrol tankers of the officers have also caught fire. The fire is unstoppable now and the commanding officer is taking important decisions with his officers.


The officers know the energy levels of all the N animals in the forest at the moment. It is a tough decision for them as they can only save exactly X animals because of the current situation of the transports they have. Since, the animals are pride of the forest, the energy level of the animals are represented with P. All the animals with energy level equal to P or greater than P can board the available transports and they will be moved to a safer place. But since the capacity is for exactly X animals it is going to be tough to figure out.


Officer needs your help to figure out the minimum energy level P such that they can get exactly X animals to transport. If it is not possible to save exactly X animals, then you should respond with -1 so that they can think of some other plan. The officers are busy trying to get control of the fire and are counting on you to figure out the minimum P to save and transport exactly X animals. 



Example:

Number of animals, N = 5

Energy level of N animals = { 1, 3, 2, 4, 5 }

Current available capacity, X = 4



You should choose P = 2, so that exactly 4 animals with energy levels (2, 3, 4 and 5) can be saved as these have energies greater than or equal to P.



Input Format
The first line of input consists of two space-separated integers, N (number of animals) and X (available capacity for animals that can be transported).

The second line of input consists of N space-separated integers, representing the energy of all the animals.



Constraints
1<= N <=10^5

1<= X <=N

1<= arr[i] <=10^12



Arr[i] represents the energy level of the ith animal.



Output Format
Print the minimum energy level P such that exactly X animals can be saved or transported. If it is not possible to save exactly X animals, then print -1.

Sample TestCase 1
Input
5 4
1 3 2 4 5
Output
2
*/


#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *a[])
{
    int n, x;
    cin >> n >> x;

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }

    sort(arr.begin(), arr.end());

    int ans = -1;

    int count = 0, totalCount = 0;
    int i = n-1;
    while(i >= 0) {
        count++;
        while(arr[i] == arr[i-1] && i != 0) {
            count++;
            i--;
        }
        if(count == x) {
            ans = arr[i];
            break;
        }
        i--;
    }

    // ans = arr[n-x];
    cout << ans << endl;

	return 0;
}