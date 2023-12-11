/*
Problem Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph-_920545?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*M)
Space Complexity: O(N*M)
*/

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
	vis[node] = 1;
	pathVis[node] = 1;
	
	for(auto adjacentNode: adj[node]) {
		if(!vis[adjacentNode]) {
			if(dfs(adjacentNode, adj, vis, pathVis)) return true;
		} else if(pathVis[adjacentNode]) return true;
	}
	
	pathVis[node] = 0;
	return false;
}

void adjacencyList(vector<vector<int>>& edges, vector<int> adj[]) {
	for(auto i: edges) {
		adj[i[0]].push_back(i[1]);
	}
}

bool isCyclic(vector<vector<int>>& edges, int v, int e) {
	vector<int> vis(v);
	vector<int> pathVis(v);
	vector<int> adj[v];

	adjacencyList(edges, adj);
	for(int i = 0; i < v; i++) {
		if(!vis[i] && dfs(i, adj, vis, pathVis)) return true;
	}
	return false;
}
