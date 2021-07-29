// { Driver Code Starts
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral
int value(char ch){
    if(ch == 'I') return 1;
    if(ch == 'V') return 5;
    if(ch == 'X') return 10;
    if(ch == 'L') return 50;
    if(ch == 'C') return 100;
    if(ch == 'D') return 500;
    if(ch == 'M') return 1000;
    
}
int romanToDecimal(string &str) {
   int s1 ,s2 ;
   int res =0;
   for(int i=0 ;i<str.size();++i){
       int s1 = value(str[i]);
       if(i+1<str.size()){
           s2 = value(str[i+1]);
           //if the value of current char is greater than of equal to next char then
           //simply add the value of curr char in res
           if(s1>=s2){
               res+=s1;
           }
           //else add the value of next char minus the current char
           //e.g "IV" I->1 and V->5 hence add res = 5-1 = 4
           else{
               res += s2 -s1;
               i++;
           }
       }
       // if there is only one char then directly add its value
       else{
           res+=s1;
       }
   }
   return res;
   
   
}