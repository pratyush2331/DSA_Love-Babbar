// HW-6

// #include<iostream>
// using namespace std;

/*
OUTPUT-1
void update(int a){
       a = a / 2;
}

int main(){
       int a = 10;
       update(a);
       cout<<a<<endl;
       return 0;
}
*/


/*
// OUTPUT-2
int update(int a){
       a -= 5;
       return a;
}

int main(){
       int a = 15;
       update(a);
       cout<<a<<endl;
}
*/


/*
int update(int a){
       int ans = a * a;
       return ans;
}

int main(){
       int a = 14;
       a = update(a);
       cout<<a<<endl;
}
*/








// HW-5: nth term of fibonacci series
// fibonacci series: 0 1 1 2 3 5 8 13 21...

// #include<iostream>
// using namespace std;

// int fibonacci(int n){
//        if(n <= 1)
//            return n;
       
//        int a = 0, b = 1, c;
//        for(int i = 2; i<=n; i++){
//               c = a+b;
//               a = b;
//               b = c;
//        }

//        return c;
// }

// int main(){
//        int n;
//        cout<<"Enter n: ";
//        cin>>n;

//        cout<<n<<"th term = "<<fibonacci(n);
//        return 0;
// }









// HW-4: Total no. of set bits of two numbers

// #include<iostream>
// using namespace std;

// int count1(int num){
//        int count = 0;
//        while(num){
//               if(num&1)
//                      count++;
                     
//               num = num>>1;
//        }
//        return count;
// }

// int setBits(int a, int b){
//        return count1(a) + count1(b);
// }

// int main(){
//        int a, b;
//        cout<<"Enter a, b: ";
//        cin>>a>>b;

//        cout<<"Total no. of set bits = "<<setBits(a, b);
//        return 0;
// }







// HW-3: AP

// #include<iostream>
// using namespace std;

// int an(int num){
//        return 3*num + 7;
// }

// int main(){
//        int n;
//        cout<<"\t AP \nan = (3*n + 7)\n";
//        cout<<"Enter n: ";
//        cin>>n;

//        cout<<"an = "<<an(n);
//        return 0;
// }








// HW-2: No. of notes

// #include<iostream>
// using namespace std;

// int main(){

//     int amount;
//     cout << "Enter Amount: ";
//     cin >> amount;
    
//     cout << "No. of Notes = " << endl;
//     while(amount){
//         switch(1){
//             case 1: cout << amount / 100 << " X 100" << endl;
//                    amount %= 100;
//             case 2: cout << amount / 50 << " X 50" << endl;
//                    amount %= 50;
//             case 3: cout << amount / 20 << " X 20" << endl;
//                    amount %= 20;
//             case 4: cout << amount / 10 << " X 10" << endl;
//                    amount %= 10;
//             case 5: cout << amount / 1 << " X 1" << endl;
//                    amount %= 1;
//         }
//     }

    // while(amount){
    //     if(amount >= 100){
    //         cout<<amount / 100<<"\t";
    //         amount = amount%100;
    //     }

    //     if(amount >= 50){
    //         cout<<amount / 50<<"\t";
    //         amount = amount % 50;
    //     }

    //     if(amount >= 20){
    //         cout<<amount / 20<<"\t";
    //         amount = amount % 20;
    //     }  

    //     if(amount >= 10){
    //         cout<<amount / 10<<"\t";
    //         amount = amount % 10;
    //     }      

    //     if(amount >= 1){
    //         cout<<amount / 1<<"\t";
    //         amount = amount % 1;
    //     } 

    // }


//     return 0;
// }









// HW-1: Calculator

// int main(){
//     int a, b;
//     char op;
//     cout<<"Enter a, b: ";
//     cin>>a>>b;
//     cout<<"Enter Operator: +, -, *, /, %: ";
//     cin>>op;

//     switch(op){
//         case '+': cout<<"a + b = "<<a+b<<endl;
//                   break;
//         case '-': cout<<"a - b = "<<a-b<<endl;
//                   break;
//         case '*': cout<<"a * b = "<<a*b<<endl;
//                   break;
//         case '/': cout<<"a / b = "<<a/b<<endl;
//                   break;
//         case '%': cout<<"a % b = "<<a%b<<endl;
//                   break;
//         default: cout<<"Invalid Operator!"<<endl;
//     }

//     return 0;
// }