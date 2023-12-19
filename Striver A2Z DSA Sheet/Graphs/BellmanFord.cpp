/*
Problem Link: https://www.codingninjas.com/studio/problems/bellman-ford_2041977?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V*E)
Space Complexity: O(N)
*/

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) dist[v] = dist[u] + wt; 
        }
    }
    
    return dist;
}