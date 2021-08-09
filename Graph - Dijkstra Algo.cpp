#include <iostream>
#include<bits/stdc++.h>
#define INF INT_MAX 
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0 ;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back9({u,w});
    }
    
    int source;
	cin >> source;
	priority_queue<pair<int,int>> ,vector<pair<int,int>> ,greater<pair<int,int>>>pq; //min heap
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	pq.push({0,source});
	while(!pq.empty()){
	    int dist = pq.top().first;
	    int node = pq.top().second;
	    for(auto it : adj[node]){
	        if(distTo[node] + it.second<distTo[it.first]){
	            distTo[it.first] = distTo[node] + it.second;
	            pq.push({distTo[it.first] ,it.first});
	        }
	    }
	    
	}
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
		
    return 0;
}