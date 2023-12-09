/*
Problem Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph-_758967?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(V+2E)
Space Complexity: O(V)
*/

class Graph {
public:
    bool dfs(int node, int parent, vector<int> adj[], int vis[]) {
        vis[node] = 1;
        
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, adj, vis)) return true;
            } else if(adjacentNode != parent) return true;
        }
        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};