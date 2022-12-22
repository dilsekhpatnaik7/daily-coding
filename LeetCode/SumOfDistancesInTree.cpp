// Problem Link: https://leetcode.com/problems/sum-of-distances-in-tree/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;
    void dfs1(int root, int i){
        for(auto x:tree[root]){
            if(x==i) continue;
            dfs1(x, root);
            count[root]+=count[x];
            res[root]+=res[x]+count[x];
        }
    }
    void dfs2(int root,int i){
        for(auto x:tree[root]){
            if(x==i) continue;
            res[x] = res[root]-count[x]+count.size()-count[x];
            dfs2(x, root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.assign(n,0);
        count.assign(n,1);

        for(auto e:edges){
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);

        return res;
    }
};