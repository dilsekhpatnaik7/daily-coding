// Problem Link: https://practice.geeksforgeeks.org/problems/e2d156755ca4e0a9b9abf5680191d4b06e52b1a8/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
     int stoneTraversal(vector<int>& arr, int idx, int n, vector<bool>& vis, vector<int>& dp){
        if(idx >= n || idx<0) return 1;
        if(dp[idx]!=-1) return dp[idx];
        if(vis[idx]) return 0;
        vis[idx] = 1;
        return dp[idx] = stoneTraversal(arr, idx + arr[idx], n, vis, dp);
    }

    int goodStones(int n,vector<int> &arr){
        vector<int> dp(n, -1);
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                stoneTraversal(arr, i, n, vis, dp);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == 1) cnt++;
        }
        return cnt;
    }    
};