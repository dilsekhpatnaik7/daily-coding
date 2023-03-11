// Problem Link: https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=pascal-triangle

#define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        ll mod = 1e9+7;
        vector<vector<ll>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for(int j = 1; j < i; j++) {
                ans[i][j] = (ans[i - 1][j - 1] + ans[i - 1][j]) % mod;
            }
        }
        return ans[n - 1];
    }
};