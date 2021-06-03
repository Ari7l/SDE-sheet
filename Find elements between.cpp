#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findUpper(vector<int>&v, int target){
    int index = -1;
    int low = 0 , high = v.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2 ;
        if(v[mid]<=target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
        if(v[mid]==target){
            index = mid;
        }
        
        
    }
    return index;
}


int findLower(vector<int>&v, int target){
     int index = -1;
    int low = 0 , high = v.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2 ;
        if(v[mid]>=target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        if(v[mid]==target){
            index = mid;
        }
        
        
    }
    return index;
}

int betweenEle(vector<int>&v ,int n ,int m){
  // we want to find the last occurance n
  int last = findUpper(v,n);
  //we want to find the first occurance of m
  int first = findLower(v,m);
  if(last==0 || first ==-1) return -1;
  return first - last-1;
}




int main() {
    vector<int>v{3, 3, 3, 4, 5, 6, 7, 8, 8, 8};
    int m,n;
    cin>>n>>m;
    cout<<betweenEle(v,n,m);

}