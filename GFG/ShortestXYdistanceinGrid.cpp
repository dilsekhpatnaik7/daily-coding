// Problem Link: https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        vector<pair<int,int>>x,y;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 'X') x.push_back({i,j});
                else if(grid[i][j] == 'Y') y.push_back({i,j});
            }
        }
        int ans = INT_MAX;
        for(auto i: x) {
            int xi = i.first, xj = i.second;
            for(auto j: y) {
                int yi = j.first, yj = j.second;
                ans = min(ans, (abs(xi - yi)) + abs(xj - yj));
                if(ans == 1) return 1;
            }
        }
        return ans;
    }
};