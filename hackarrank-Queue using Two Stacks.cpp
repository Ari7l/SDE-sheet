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
   // we are using two stacks to create FIFO rule of queue. One stack is acting as the front and other as the rear.
   // we are pushing all the elements in stack st1 which is tail i guess and the if Dequeue is called we are push all the elements in the stack2 
   //hence achieving the reverse internal order of queue by stack now the top ele of st2 is front element and hence we can remove it or return it 
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
