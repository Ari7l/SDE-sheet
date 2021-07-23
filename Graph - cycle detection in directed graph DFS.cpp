#include <bits/stdc++.h>
using namespace std;
 
bool cycleDfs(int src, vector<int> adj[], int vis[],int dfsVis[]) {
    vis[src]=1;
    dfsVis[src]=1;
     for(auto it : adj[src]) {
        if(vis[it] == 0) {
            if(bipartiteDfs(it, adj, vis,dfsVis)) return true;
            }
         else if(dfsVis[it]==1) return true;
        
        }
     dfsVis[it]=0;
        
    return false; 
}
bool cycleDetect(vector<int> adj[], int n) {
    int vis[n];
    int dfsVis[n];
    memset(vis, 0, sizeof vis); 
    memset(vis, 0, sizeof dfsVis); 
    for(int i = 0;i<n;i++) {
        if(vis[i]==0){
            if(cycleDfs(i, adj, vis,dfsVis)){
                return true;
            }
        }
    }
    return false; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(cycleDetect(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}
