/*
Problem Link: https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

int solve(int i, int k, vector<int> &height, vector<int> &dp) {
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];

    int minSteps = INT_MAX;
    for(int j = 1; j <= k; j++) {
        if(i - j >= 0) {
            int jump = solve(i - j, k, height, dp) + abs(height[i] - height[i - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[i] = minSteps;
}

int solve2(int n, int k, vector<int> &height, vector<int> &dp) {
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        int minSteps = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n - 1];
}

int minimizeCost(int n, int k, vector<int> &height){
    // Recursion + Memoization
    vector<int> dp(n, -1);
    return solve(n - 1, k, height, dp);

    // Tabulation
    return solve2(n, k, height, dp);
}