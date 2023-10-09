// F <--> C temperature Converter

#include<iostream>
using namespace std;

int main(){
    float temp=0.0;
    char ch;
    cout<<"Enter F: C --> F \t\t OR \t\t C: F --> C\n";
    cin>>ch;
    if(ch=='F' || ch=='f'){
        cout<<"Enter temperature in Celsius : ";
        cin>>temp;
        cout<<endl<<(temp*9/5)+32<<" F\n";
    }
    else if(ch=='C' || ch=='c'){
        cout<<"Enter temperature in Fahrenheit : ";
        cin>>temp;
        cout<<endl<<(temp-32)*5/9<<" C\n";
    }
    else{
        cout<<"Enter RIGHT Character\n";
    }
    return 0;
}