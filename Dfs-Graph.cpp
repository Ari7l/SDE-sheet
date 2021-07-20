#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[] , int u ,int v){
    adj[u].push_back(v); //for each vertices add its adjcent node into its indexed vector
    adj[v].push_back(u); 
}
void dfs(int node ,vector<int>adj[], vector<int>&vis ,vector<int>&res){
    res.push_back(node) ;
    cout<<node<<" ";
    vis[node] =1;
    for(auto it: adj[node]){
        if(vis[it]==0){
            dfs(it,adj,vis,res); //calling dfs on adjacent of curent node
        }
    }
    
}
vector<int>dfsGraph(vector<int>adj[] ,int V){
    vector<int>res;
    vector<int>vis(V ,0);
    for( int i =0 ; i<V; ++i){
        if(vis[i]==0){
           dfs(i,adj,vis,res);
            
        }
    }
    return res;
}
int main() {
    int V = 5 ;
    vector<int>adj[V] ;//adjency list array of vectors
    addEdge(adj, 0, 1); // adding edges between nodes/vertices
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    dfsGraph(adj,V);
    
    
}
//TIME : O(V+E);
//space : O(V+E);