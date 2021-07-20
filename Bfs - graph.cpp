
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[] , int u ,int v){
    adj[u].push_back(v); //for each vertices add its adjcent node into its indexed vector
    adj[v].push_back(u); 
}
vector<int>bfs(vector<int>adj[] ,int V){
    vector<int>res;
    vector<int>vis(V ,0);
    for( int i =0 ; i<V; ++i){
        if(vis[i]==0){
            queue<int>q ;
            q.push(i) ;
            while(!q.empty()){
                int curr = q.front() ;
                q.pop();
                res.push_back(curr);
                cout<<curr<<" ";
                for(auto i: adj[curr]){
                    if(vis[i]==0){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }
            
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
    bfs(adj,V);
    
    
}