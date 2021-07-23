#include <iostream>
using namespace std;
//topological sort occures only in a Directed Acyclic graph 
//if given edge is given by (u,v) then for every u must come before v then the grqaphg is sorted
//here we use a stack to store the topological order 
class Solution{
    public:
    void topoSortDfs(int node ,vector<int>adj[] , stack<int>&st ,vector<int>&vis){
    vis[node]=1;
    for(auto it :adj[node]){
        if(vis[it]==0 ){
            topoSortDfs(it,adj,st,vis);
        }
    }
    st.push(node);
    }

    vector<int> topoSort(int N ,vector<int>adj[]){
        vector<int>vis(N ,0);
        stack<int>st;
        for(int i= 0 ;i<N; ++i){
            if(vis[i]==0){
                topoSortDfs(i,adj,st,vis);
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
    
    
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
} 