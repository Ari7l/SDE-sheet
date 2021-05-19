#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
stack<int>st1;
stack<int>st2;

class solution{
public:
   void Enqueue( int n){
       st1.push(n);
   }
   void Dequeue(){
       if(st2.empty()){
           while(!st1.empty()){
           int temp = st1.top();
           st1.pop();
           st2.push(temp);
       }
       }
       st2.pop();
       
   }
   int PrintFirst(){
       if(st2.empty()){
           while(!st1.empty()){
           int temp = st1.top();
           st1.pop();
           st2.push(temp);
       }
       }
       return st2.top();
   }   
};
int main() {
    int q;
    cin>>q;
    while(q--){
       int x;
    cin>>x;
    solution obj;
    if(x==1){
        int y;
        cin>>y;
        obj.Enqueue(y);
    }
    else if(x==2){
        obj.Dequeue();
    }
    else{
        cout<<obj.PrintFirst()<<"\n";
    } 
    }
    
    
    return 0;
}
