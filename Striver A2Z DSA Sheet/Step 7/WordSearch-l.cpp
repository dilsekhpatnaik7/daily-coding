/*
Problem Link: https://www.codingninjas.com/studio/problems/word-search---l_892986?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N ^ 2 * 4 ^ N)
Space Complexity: O(4 ^ N + N ^ 2 + N + N)
*/

bool solve(int i, int j, int index, vector<vector<char>>& board, string& word, vector<vector<int>>& vis, int di[], int dj[]) {
    if(index == word.length()) return true;

    for(int k = 0; k < 4; k++) {
        int nexti = i + di[k], nextj = j + dj[k];
        if (nexti >= 0 && nexti < board.size() && nextj >= 0 &&
            nextj < board[0].size() && !vis[nexti][nextj] &&
            board[nexti][nextj] == word[index]) {
            vis[nexti][nextj] = 1;
            if (solve(nexti, nextj, index + 1, board, word, vis, di, dj))
            return true;
            vis[nexti][nextj] = 0;
        }
    }
    return false;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) {
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == word[0]) {
                vis[i][j] = 1;
                if(solve(i, j, 1, board, word, vis, di, dj)) return true;
                vis[i][j] = 0;
            }
        }
    }
    return false;
}