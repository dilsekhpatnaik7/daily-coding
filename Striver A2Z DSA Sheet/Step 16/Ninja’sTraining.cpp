/*
Problem Link: https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N*3*4)
Space Complexity: O(N*4 + N)
*/

int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(day == 0) {
        int maximum = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maximum = max(maximum, points[0][task]);
            }
        }
        return maximum;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maximum = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + solve(day - 1, task, points, dp);
            maximum = max(maximum, point);
        } 
    }

    return dp[day][last] = maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}