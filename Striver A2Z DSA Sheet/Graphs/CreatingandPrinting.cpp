/*
Problem Link: https://www.codingninjas.com/studio/problems/creating-and-printing_1214551?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<int> t[n];
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        t[u].push_back(v);
        t[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        adj[i].push_back(i);
        for(int j = 0; j < t[i].size(); j++) {
            adj[i].push_back(t[i][j]);
        }
    }
    return adj;
}