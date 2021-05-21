#include<iostream>
#include<cstring>
#define MAX 256 //there are max 256 characters
using namespace std;
//this function 
bool compare(char arr1[], char arr2[]){
    for(int i=0;i<MAX;++i){
        if(arr1[i]!=arr2[i]) return false;
    }
    return true;
}
// this fucntion is to check if the pat is the substring of the text string in the 
//shffled form
bool shuffle( char *pat, char *text){
    int N = strlen(text);
    int M = strlen(pat);
    if(M>N) return false;
    // countP[]: Store count of all characters of pattern
    // countTW[]: Store count of current window of text
    char countP[MAX] = {0} ,countTW[MAX] = {0} ;
    //counting the freq of all characters for the first window 
    for(int i =0 ;i<M; ++i){
        countP[pat[i]]++;
        countTW[text[i]]++;
    }
    for(int i=M ;i<N ;++i){
        //check if the first window contain same number of occurance of charac.
        if(compare(countP,countTW));
        //this stores the count for next window
        countTW[text[i]]++;
        //this decrement the count of previous window
        countTW[text[i-M]]--;
    }
    //this checks for last window 
     if (compare(countP, countTW))
        return true;
    return false;
    
}


int main() {
    char text[] = "BACDGABCDA";
    char pat[] = "ABCD";
    if (shuffle(pat, text))
       cout << "Yes";
    else
       cout << "No";
    return 0;
}