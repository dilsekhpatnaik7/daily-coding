// Problem Link: https://leetcode.com/problems/all-paths-from-source-to-target/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int node , vector<int> adj[] , int n){
        path.push_back(node);
        if(node == n-1){
            ans.push_back(path);
        }
        else {
            for(auto it : adj[node]){
                dfs(it , adj , n);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];

        for(int i=0 ; i<n ; i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }

        dfs(0 , adj , n);
        return ans;
    }
};