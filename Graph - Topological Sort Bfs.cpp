#include <iostream>
using namespace std;
//kahn's Algorithm
vector<int> topoSortBfs(vector<int>adj[] ,int n){
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
    vector<int>sorted;
    //we will start with node with zero indegree and traverse its adjencent nodes
    //and decrement their indegrees so that they only have outgoing paths
    //and then push into queue
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        sorted.push_back(curr);
        for(auto it : adj[curr]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }

    }
    return sorted;    

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