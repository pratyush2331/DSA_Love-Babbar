// passByValue(n)

#include<iostream>
using namespace std;

void passByValue(int n){
    n++;
    cout<<"Inside function, n = "<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter n = ";
    cin>>n;

    passByValue(n);
    cout<<"After function call, n = "<<n<<endl;
    return 0;
}









// isPrime(n)

// #include<iostream>
// using namespace std;

// // 0 --> Prime,      1 --> Not Prime
// bool isPrime(int num){
//     for(int i = 2; i < num; i++){
//         if(num%i == 0)
//             return 1;
//     }
//     return 0;
// }

// int main(){
//     int n;
//     cout<<"Enter number: ";
//     cin>>n;

//     if(isPrime(n) == 0)
//         cout<<"Prime";
//     else 
//         cout<<"Not Prime";
//     return 0;
// }








// printCounting(n)

// #include<iostream>
// using namespace std;

// void printCounting(int num){
//     for(int i = 0; i <= num; i++){
//         cout<<i<<endl;
//     }
// }

// int main(){
//     int n;
//     cout<<"Enter number: ";
//     cin>>n;
//     printCounting(n);
//     return 0;
// }








// nCr(n,r) = n! / (r! * (n-r)!)

// #include<iostream>
// using namespace std;

// int fact(int n) {
//     // base case
//     if(n <= 1)
//         return 1;
    
//     // recurrence relation
//     return n*fact(n-1);
// }

// /*
// int factorial(int num){
//     int fact = 1;
//     for(int i=1; i<=num; i++){
//         fact *= i;
//     }
//     return fact;
// }
// */

// int nCr(int n, int r){
//     int num = factorial(n);
//     int den = factorial(r) * factorial(n-r);

//     return num/den;
// }

// int main(){
//     int n, r;
//     cout<<"Enter n, r = ";
//     cin>>n>>r;

//     cout<<"nCr(n,r) = "<<nCr(n,r);
//     return 0;
// }








// isEven

// #include<iostream>
// using namespace std;

// 1 --> Even,     0 --> Odd
// bool isEven(int a){
//     if(a & 1) // Odd
//         return 0;
//     return 1; // Even
// }

// int main(){
//     int num;
//     cin>>num;

//     if(isEven(num))
//         cout<<"Number is Even"<<endl;
//     else 
//         cout<<"Number is Odd"<<endl;

//     return 0;
// }










// function

// #include<iostream>
// using namespace std;

// int power(){
//     int a, b;
//     cout<<"Enter a, b:";
//     cin>>a>>b;
//     int answer = 1;
//     for(int i=1; i<=b; i++){
//         answer *= a;
//     }
//     return answer;
// }

// int main(){

//     int ans = power();
//     cout << "power(a, b) = " << ans;
//     return 0;
// }










// switch statement - nested switch statement - exit(0);

// #include<iostream>
// using namespace std;

// int main(){
//     char ch = '1';
//     int num = 1;
//     cout<<endl;

//     while(1){
//         switch(ch){
//             case 1: cout<<" Number 1 "<<endl;
//             break;

//             case '1': cout<<" character 1 "<<endl;
//                       switch(num){
//                           case 1: cout<<" Value of num is "<<num<<endl;
//                           break;
//                           continue; // it'll not be executed due to break statement
//                       }
//             //exit(0); // similar to return 0;
//             break;

//             default: cout<<" It's a default case! "<<endl;
//         }
//         cout<<"Hi";
//     }
//     return 0;
// }