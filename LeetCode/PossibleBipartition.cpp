// Problem Link: https://leetcode.com/problems/possible-bipartition/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
    private:
    bool check(int start,int V,vector<int> adj[],vector<int> &col){
        queue<int> q;
        q.push(start);col[start]=0;
        while(!q.empty()){
            int node=q.front();q.pop();
            for(auto it :adj[node]){
                if(col[it]==-1){
                    col[it]=!col[node];
                    q.push(it);
                }
                else if(col[it]==col[node]) return false; // if colour of adjacent nodes are same
                
            }
        }return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //bipartite graph
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
            
        }
        vector<int> col(n+1,-1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(check(i,n,adj,col)==false) return false;
            }
        }
        return true;
        
    }
};