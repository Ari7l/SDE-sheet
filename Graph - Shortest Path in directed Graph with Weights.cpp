#include <iostream>
#include<bits/stdc++.h>
#define INF INT_MAX 
using namespace std;

void findTopoSort(vector<pair<int,int>>adj[] ,int vis[] , stack<int>&st,int node){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            findTopoSort(adj,vis,st,it.first);
        }
    }
    st.push(node);
}


void shortestPath(vector<pair<int,int>>adj[], int src, int N){
    int vis[N]={0};
    stack<int>st;
    for(int i=0 ;i<N ;++i){
        if(!vis[i]){
            findTopoSort(adj,vis,st,i);
        }
    }
    int dist[N];
    for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 
    dist[src]= 0;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(dist[curr]!=INT_MAX){
            for(auto it: adj[curr]){
                if(dist[curr]+it.second <dist[it.first]){
                    dist[it.first] = dist[curr]+it.second;
                }
            }
        }
    }
    for(int i=0 ;i<N ;++i){
        (dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0 ;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    shortestPath(adj,0,n);
    return 0;
}
// consider src = 0;
//6 7
//0 1 2
//0 4 1
//1 2 3
//2 3 6
//4 2 2
//4 5 4
//5 3 1