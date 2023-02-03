// Problem Link: https://practice.geeksforgeeks.org/problems/2e068e2342b9c9f40cfda1ed8e8119542d748fd8/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0, k = 0;
        pair<int, int> ans;
        while(i >= 0 && j >= 0 && i < n && j < m){
            ans = {i, j};
            if(matrix[i][j] == 1){
                matrix[i][j] = 0;
                k = (k+1)%4; 
            }
            i = i + dir[k].first;
            j = j + dir[k].second;
        }
        return ans;
    }
};