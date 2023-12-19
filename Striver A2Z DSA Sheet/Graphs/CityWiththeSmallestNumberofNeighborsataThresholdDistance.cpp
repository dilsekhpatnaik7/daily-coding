/*
Problem Link: https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

Time Complexity: O(N^3)
Space Complexity: O(N*N)
*/

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for(auto i: edges) {
            matrix[i[0]][i[1]] = i[2];
            matrix[i[1]][i[0]] = i[2];
        }
        
        for(int i = 0; i < n; i++) matrix[i][i] = 0;
        
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][via] == INT_MAX || matrix[via][j] == INT_MAX) continue;
                    
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        int countCity = n;
        int city = -1;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] <= distanceThreshold) count++;
            }
            
            if(count <= countCity) {
                countCity = count;
                city = i;
            }
        }
        return city;
    }
};