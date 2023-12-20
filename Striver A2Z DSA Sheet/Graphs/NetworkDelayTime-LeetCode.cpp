/*
Problem Link: https://leetcode.com/problems/network-delay-time/description/

Time Complexity: O(E*log(V))
Space Complexity: O(N)
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for(auto i: times) dist[i[0]][i[1]] = i[2];
        for(int i = 1; i <= n; i++) dist[i][i] = 0;

        for(int via = 1; via <= n; via++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dist[k][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};