/*
Problem Link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

Time Complexity: O(N ^ 2 * 4 ^ N)
Space Complexity: O(N ^ 2)
*/

class Solution{
    public:
    void solve(int i, int j, vector<vector<int>> &m, int n, vector<string>& ans, string moves, vector<vector<int>>& vis, int di[], int dj[]) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(moves);
            return;
        }
        
        string dir = "DLRU";
        for(int index = 0; index < 4; index++) {
            int nexti = i + di[index];
            int nextj = j + dj[index];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, m, n, ans, moves + dir[index], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }
};