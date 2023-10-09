// Loop Basics

#include<iostream>
using namespace std;

// printing 1 to n using for loop
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;

//     cout<<"Printing number from 1 to "<<n<<":\n";
//     for(int i=1; i<=n; i++){
//         cout<<i<<endl;
//     }
//     return 0;
// }



// for loop without any arguments
// int main(){
//     int n;
//     cout<<"Enter the value of n: ";
//     cin>>n;
//     cout<<"Printing number from 1 to "<<n<<":\n";
//     int i=1;
//     for(;;){
//         if(i<=n)
//             cout<<i<<endl;
//         else
//             break;
//         i++;
//     }
//     return 0;
// }



// using more than two arguments
// int main(){
//     for(int a=0, b=1, c=2; a>=0 && b>=1 && c>=2; a--, b--, c--){
//         cout<<a<<" "<<b<<" "<<c<<endl;
//     }
//     return 0;
// }



// print sum upto n
// int main(){
//     int n;
//     cin>>n;

//     int sum=0;
//     for(int i=1; i<=n; i++){
//         sum += i;
//     }
//     cout<<"Sum = "<<sum;
//     return 0;
// }



// fibonacci series : 0,1,1,2,3,5,8,13,21...
// int main(){
//     int n;
//     cout<<"Enter n > 2: "
//     cin>>n;

//     int a=0, b=1, c;
//     cout<<a<<" "<<b<<" ";
//     for(int i=1; i<n-1; i++){
//         c=a+b;
//         cout<<c<<" ";
//         a=b;
//         b=c;
//     }
//     return 0;
// }



// Find n is prime or not
// int main(){
//     int n;
//     cin>>n;

//     int i;
//     for(i=2; i<n; i++){
//         if(n%i == 0)
//             break;
//     }
//     if(i==n)
//         cout<<"Prime!";
//     else
//         cout<<"Not Prime";
//     return 0;
// }



// continue statement
// int main(){
//     int n;
//     cout<<"Enter any number: ";
//     cin>>n;

//     int skip;
//     cout<<"Enter any no. to SKIP b/w 1 to n: ";
//     cin>>skip;

//     for(int i=1; i<=n; i++){
//         if(i==skip)
//             continue;
//         cout<<i<<" ";
//     }
//     return 0;
// }
