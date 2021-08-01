
  
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution{
   public:
   void addEdge(vector<int>adj[] ,int u ,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        }
        
   public:
   //we are trying to find the shortest path from the src node to any given node;
   //this is undirected graph with unit weights for the edges 
        void shortestPathBfs(vector<int>adj[] , int V ,int src){
           int dist[V] ;
           //this is the distance array which will store the shortest dist of nodes from the src node
           //initially we will fill it with INF
           memset(dist,INT_MAX,sizeof dist);
           dist[src]= 0;//dist of src node from itself is 0
           queue<int>q;
           q.push(src);
           while(!q.empty()){
               int curr = q.front();
               q.pop();
               //traverse the graph using BFS , we know that the adj nodes are unit dist away as the edges are unit weighted hence 
               //we will update the minimum dist every time we visit the node
               for(auto it:adj[curr]){
                   if(1+dist[curr]<dist[it]){
                       dist[it] = 1+dist[curr];
                       q.push(it);
                   }
               }
           }
           for(int i = 0;i<V;i++) cout << dist[i] << " "; 
           
        }
    
};

 
int main() {
    int V = 5 ;
    Solution obj;
    vector<int>adj[V] ;//adjency list array of vectors
    obj.addEdge(adj, 0, 1); // adding edges between nodes/vertices
    obj.addEdge(adj, 0, 4);
    obj.addEdge(adj, 1, 2);
    obj.addEdge(adj, 1, 3);
    obj.addEdge(adj, 1, 4);
    obj.addEdge(adj, 2, 3);
    obj.addEdge(adj, 3, 4);
    
    obj.shortestPathBfs(adj ,V, 0);
    
}
//time : O(V+E)
//space : O(V+E)
