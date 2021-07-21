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
    bool isCyclic(vector<int>adj[] , vector<bool>&vis, int node){
         queue<pair<int,int>>q; // we are making use of pairs to store the path from which the we came from
         vis[node]=1;           //i.e its parent node 
         q.push({node ,-1});
         while(!q.empty()){
             auto curr = q.front();
             for(auto it : adj[node]){
                 if(!vis[it]){
                     q.push({it,node});
                     vis[it]=1;
                 }
                 //if a adjacent node is already visited then we will check if the parent node of current node 
                 // is same as the node itself ..if it is same it means we just came from that node and its not
                 // a cycle but if its not same it means we have already visited that node by some other way]
                 // hence a cycle is detected
                 else if(curr.second!=it) return true;
             }

         }
         return false;
    }
        
   public:
        bool bfs(vector<int>adj[] , int V){
            vector<bool>vis(V+1 , 0);
            
            for(int i=1 ;i<=V ;++i){
                if(!vis[i]){
                    if(isCyclic(adj ,vis, i)) return true;
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
    cout<<obj.bfs(adj,V);
    
    
}
//time : O(V+E)
//space : O(V+E)