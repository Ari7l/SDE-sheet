#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printAllSubSeq(string s1 ,string s2){
    if(s1.empty()){
        cout<<s2<<" ";
        return;
    }
    printAllSubSeq(s1.substr(1),s2+s1[0]);//add the current charcter in ans 
    printAllSubSeq(s1.substr(1),s2);//dont add the current character in ans
    
}

int main() {
    string input = "abcd";
    string output = "";
    printAllSubSeq(input, output);
}