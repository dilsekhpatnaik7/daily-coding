// Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < n; ++j)
                A[i][j] += min(A[i-1][j], min(A[i-1][max(0,j-1)],A[i-1][min(n-1,j+1)]));
        return *min_element(A[n-1].begin(), A[n-1].end());
    }
};