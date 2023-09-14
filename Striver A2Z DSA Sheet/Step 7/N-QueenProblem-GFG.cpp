/*
Problem Link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

Time Complexity: O(N!)
Space Complexity: O(N ^ 2)
*/

class Solution{
public:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        
        vector<vector<int>> res;
        for(int i = 0; i < ans.size(); i++) {
            vector<int> v;
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(ans[i][j][k] == 'Q') v.push_back(k + 1);
                }
            }
            res.push_back(v);
        }
        sort(res.begin(), res.end());
        return res;
    }
};