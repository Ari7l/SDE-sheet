
#include <iostream>
using namespace std;
// using kahn's Algorithm
// for cycle detection in directed graph 
// we know that the topological sort is only possible in  Directed Acyclic Graph and hence we cant find topological sort for 
//a graph then it must be cyclic
bool topoSortBfs(vector<int>adj[] ,int n){
    //this vector will tell us the no. of incoming edges to a given node
    vector<int>indegree(n,0);
    for(int i=0 ;i<n;++i){
        for(auto it :adj[i]){
            indegree[it]++;
        }
    }
    //we will start with the nodes with 0 indegrees bcoz this node will have only
    //outgoing paths and hence in sorting order it should come before any other 
    //nodes
    queue<int>q;
    for(int i=0;i<n;++i){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //we will start with node with zero indegree and traverse its adjencent nodes
    //and decrement their indegrees so that they only have outgoing paths
    //and then push into queue
    int cnt =0;
   
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cnt++;
        for(auto it : adj[curr]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }

    }
     //topo sort is nothing but a order of all nodes in the graph and if it is possible then cnt will be N i.e no. of nodes in graph 
    // and hence we can say that it is Acyclic
     if(cnt==n) return false;
     
     return true;

}




int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	}
	
	vector<int> res = topoSortBfs(adj,n);
	return 0;
}