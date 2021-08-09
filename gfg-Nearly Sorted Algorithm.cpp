#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int>arr(n);
	    for(int i=0 ;i<n;++i) cin>>arr[i];
	    priority_queue<int , vector<int>, greater<int>>pq;
	    for(int i=0;i<=k;++i){
	        pq.push(arr[i]);
	    }
	    for(int i=k+1 ;i<n;++i){
	        cout<<pq.top()<<" ";
	        pq.pop();
	        pq.push(arr[i]);
	    }
	    while(pq.size()>0){
	         cout<<pq.top()<<" ";
	         pq.pop();
	    }
	    cout<<"\n";
	}
	return 0;
}