// Problem Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<bool> vis;
    int dfs(vector<vector<int>> &graph,vector<bool>& hasApple,int node,int cost) {
        if(vis[node]) return 0;
        vis[node] = true;
        int childrenCost = 0;
        for(auto x: graph[node])
            childrenCost += dfs(graph, hasApple, x, 2);
        if(childrenCost == 0 && hasApple[node] == false) return 0;
        return (childrenCost + cost);
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        vis=vector<bool>(n, false);
        for(auto &x: edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        return dfs(graph,hasApple,0,0);
    }
};