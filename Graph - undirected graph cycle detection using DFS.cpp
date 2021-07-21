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
    bool isCyclic(vector<int>adj[] , vector<bool>&vis, int node, int parent){
        vis[node]=1;
        for(auto it :adj[node]){
            if(!vis[it]){ 
                if(isCyclic(adj,vis,it,node)) return true;
            }
            //dfs will run till all nodes are unvisited , once we wncounter a node which is already visited we will check if that node is same as our
            //parent node i.e the node from which we came from if its not then we can say we have encountered a cycle 
            else if(it!=parent) return true;
            
        }
        return false ;
    }
        
   public:
        bool dfs(vector<int>adj[] , int V){
            vector<bool>vis(V+1 , 0);
            
            for(int i=1 ;i<=V ;++i){
                if(!vis[i]){
                    if(isCyclic(adj ,vis, i ,-1)) return true;
                }
            }
            return false;
        }
    
};

 
int main() {
    int V = 10 ;
    Solution obj;
    vector<int>adj[V+1] ;//adjency list array of vectors
    obj.addEdge(adj, 1, 2); // adding edges between nodes/vertices
    obj.addEdge(adj, 2, 4);
    obj.addEdge(adj, 3, 5);
    obj.addEdge(adj, 5, 6);
    obj.addEdge(adj, 5, 10);
    obj.addEdge(adj, 6, 7);
    obj.addEdge(adj, 7, 8);
    obj.addEdge(adj, 8, 9);
    obj.addEdge(adj, 9, 10);
    cout<<obj.dfs(adj,V);
    
    
}