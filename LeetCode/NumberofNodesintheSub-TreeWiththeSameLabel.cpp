// Problem Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<int> ans;
    vector<vector<int>> g;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        g.resize(n,vector<int>{});
        for(auto it:edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs(0, -1, labels);
        return ans;
    }
    
    vector<int> dfs(int s, int par, string &labels) {
        vector<int>res(26,0);
        res[labels[s]-'a']++;
        for(int it: g[s]) {
            if(it == par)
                continue;
            vector<int> f = dfs(it, s, labels);
            for(int i = 0; i < 26; ++i) {
                res[i] += f[i];
            }
        }
        ans[s] = res[labels[s] - 'a']; 
        return res;
    }
};