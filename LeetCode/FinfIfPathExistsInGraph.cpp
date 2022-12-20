// Problem Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool PathCheck(vector<vector<int>> &adj,vector<int>&vis,int n,int source,int destination){
        if(source == destination){
            return true;
        }
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            if(node == destination){
                return true;
            }
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return false;   
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1);
        return PathCheck(adj,vis,n,source,destination);
    }
};