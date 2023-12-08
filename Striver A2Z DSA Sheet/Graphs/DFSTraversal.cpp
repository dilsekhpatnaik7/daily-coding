/*
Problem Link: https://www.codingninjas.com/studio/problems/dfs-traversal_630462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

void solve(int node, vector<int> adj[], vector<int>& vis, vector<int>& v) {
    vis[node] = 1;
    v.push_back(node);

    for(auto i: adj[node]) {
        if(!vis[i]) solve(i, adj, vis, v);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<int> adj[V];
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V);
    vector<vector<int>> dfs;
    for(int i = 0; i < V; i++) {
        vector<int> v;
        if(!vis[i]) {
            solve(i, adj, vis, v);
            dfs.push_back(v);
        }
    }
    return dfs;
}