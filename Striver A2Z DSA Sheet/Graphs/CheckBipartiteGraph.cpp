/*
Problem Link: https://www.codingninjas.com/studio/problems/check-bipartite-graph-_920551?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

#include<bits/stdc++.h>
bool bfs(int start, int col, vector<int> adj[], vector<int>& color) {
	color[start] = col;

	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int node = q.front(); q.pop();

		for(auto adjacentNode: adj[node]) {
			if(color[adjacentNode] == -1) {
				color[adjacentNode] = !color[node];
				q.push(adjacentNode);
			} else if(color[node] == color[adjacentNode]) return false;
		}
	}
	return true;
}

void makeAdjacencyList(int n, vector<vector<int>> &edges, vector<int> adj[]) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (edges[i][j] == 1) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
    }
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector<int> color(n, - 1);
	vector<int> adj[n];
	makeAdjacencyList(n, edges, adj);

	for(int i = 0; i < n; i++) {
		if(color[i] == -1 && !bfs(i, 0, adj, color)) return false;
	}
	return true;
}