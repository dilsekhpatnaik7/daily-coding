/*
Problem Link: https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> ans(V);
        for(auto i: edges) {
            int u = i.first;
            int v = i.second;
            
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        return ans;
    }
};