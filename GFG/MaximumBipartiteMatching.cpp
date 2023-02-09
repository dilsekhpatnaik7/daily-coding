// Problem Link: https://practice.geeksforgeeks.org/problems/9a88fe7ada1c49c2b3da7a67b43875e4a76aface/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    vector<int> match;
    vector<int> vis;
    
	bool solve(int p,vector<vector<int>>&g){
      for(int j=0;j<g[0].size();j++){
          if(g[p][j] && !vis[j]){
              vis[j]=1;
              if(match[j]==-1 || solve(match[j],g)){
                  match[j]=p;
                  return true;
              }
          }
      }
      return false;
    }

	int maximumMatch(vector<vector<int>>&g){
	    int p=g.size();
	    int j=g[0].size();
	    match=vector<int>(j,-1);
	    int ans=0;
	    for(int i=0;i<p;i++){
	        vis=vector<int>(j,0);
	        if(solve(i,g))ans++;
	    }
	    return ans;
	}
};