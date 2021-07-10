#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define d 256
void search(char*txt ,char *pat, int q){
    int p=0;//stores the hash value for pattern ''
    int t=0; //stores the hash value for pattern ''
    int h=1; // h = d^(M-1)
    int j ;
    int N = strlen(txt);
    int M = strlen(pat);
    for(int i=0;i<M -1 ; ++i){
        h = (h*d) % q; // modulo with prime so that it doesnt overflow e.g So assuming your hash has 11 items, 
        //the hash key 12, would be stuck into 12%11 remainder 1 – 1st  location
    }
    //calculating hash value for current window
    for( int i = 0 ; i<M ;++i){
        t = (t*d + txt[i])%q ; //taking modulo with a prime number helps generating unqiue hash value
        p = (p*d + pat[i])%q ;
    }
    for( int i=0 ; i<=N-M ;++i){
        //if the hash value for both strings is same then we will check each charcter
        if(t==p){
            for( j =0 ;j<M ;++j){
             if(txt[i+j]!=pat[j]) break;
         }
         if(j==M && j<N){
             cout<<i<<" ";
             
         }
        }
        if(i<N-M)
            t = (d*(t - txt[i]*h) + txt[i+M])%q ;//calculating the hash value for new window on the go
            //we remove the Left most character and add right most character
         if(t<0) t = t+q;// We might get negative value of t, converting it
            // to positive
         
    }
}
int main(){
   char txt[] =  "AABAACAADAABAABA";
   char pat[] = "AABA";
   int q = 101;
   search(txt , pat ,q);
}