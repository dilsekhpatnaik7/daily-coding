/*
Problem Link: https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*Target + N)
Space Complexity: O(N*Target)
*/

int solve(int index, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>& dp) {
    if(index == 0) {
        return (w / weight[0]) * profit[0];
    }
    if(dp[index][w] != -1) return dp[index][w];

    int notTake = solve(index - 1, w, profit, weight, dp);
    int take = -1e9;
    if(weight[index] <= w) {
        take = profit[index] + solve(index, w - weight[index], profit, weight, dp);
    }

    return dp[index][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}