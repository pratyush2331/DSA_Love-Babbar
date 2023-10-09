/*
                        1          
    n=5    --->         2 3       
                        3 4 5     
                        4 5 6 7   
                        5 6 7 8 9  
*/
#include<iostream>
using namespace std;

// METHOD-1
int main(){
    int n;
    cin>>n;
    int i=1;
    int count;
    while(i<=n){
        int j=1;
        count=i;
        while(j<=i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
// METHOD-2
// int main(){
//     int n;
//     cin>>n;
//     int i=1, j=1;
//     int count=1;
//     while(i<=n){
//         count=j;
//         j=1;
//         while(j<=i){
//             cout<<count<<" ";
//             count++;
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }