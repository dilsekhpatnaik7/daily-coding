// Problem Link: https://practice.geeksforgeeks.org/problems/77e1c3e12cd148f835d53eb168d4472b2ff539fa/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int maxi = 0;
        int row = 0;
        int j = N-1;
        int i = 0;
        while(i < N && j >= 0) {
             if(mat[i][j] == 1) {
                 j--;
             }
             else {
                 if(maxi < N - j - 1) {
                     maxi = N -j - 1;
                     row = i;
                 }
                 i++;
             }
        }
        if(j<0) {
            return {i,N};
        }
        return {row,maxi};
    }
};