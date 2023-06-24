// Circular Tour
// GFG : https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

#include<iostream>
using namespace std;

/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    
    // TC : O(n)
    int tour(petrolPump p[],int n) {
        int deficit = 0; // kami
        int balance = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            if(balance < 0) {
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(deficit + balance >= 0) {
            return start;
        }
        else {
            return -1;
        }
    }
    
    // BRUTE FORCE, TC : O(n^2)   --->   TLE
    /*
    int tour(petrolPump p[],int n)
    {
       for(int i = 0; i < n; i++) {
           int cnt = 1;
           int j = i;
           int ans = 0;
           while(cnt <= n) {
               int diff = p[j].petrol - p[j].distance;
               ans += diff;
               if(ans < 0) {
                   break;
               }
               j++;
               j = j%n;
               cnt++;
           }
           
           if(ans >= 0) {
               return i;
           }
       }
       
       return -1;
    }
    */
};

int main() {
    
    return 0;
}