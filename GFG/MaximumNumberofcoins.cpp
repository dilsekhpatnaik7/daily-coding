// Problem Link: https://practice.geeksforgeeks.org/problems/7ae455e552dc4e07f76bbe2adc4d4207ce1ff16e/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k = i; k <= j; k++) {
                int curr = a[i-1] * a[k] * a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
                ans = max(ans, curr);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(int N, vector <int> &a) {
        a.insert(a.begin(),1);
        a.push_back(1);
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return f(1, N, a, dp);
    }
};