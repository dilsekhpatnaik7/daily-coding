/*
Problem Link: https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N + 2E)
Space Complexity: O(N)
*/

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    if(!n) return {};
         
    vector<int> vis(n);
    vis[0] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()) {
        int node = q.front(); q.pop();
        
        bfs.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}