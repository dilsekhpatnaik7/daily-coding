/*
Problem Link: https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

Time Complexity: O(N*Target)
Space Complexity: O(N*Target)
*/

class Solution{
public:
// 	int solve(int index, int target, int num[], vector<vector<int>> &dp) {
//         if(index == 0) {
//             if(target % num[0] == 0) return target / num[0];
//             return 1e9;
//         }
//         if(dp[index][target] != -1) return dp[index][target];
    
//         int nonTake = solve(index - 1, target, num, dp);
//         int take = 1e9;
//         if(num[index] <= target) {
//             take = 1 + solve(index, target - num[index], num, dp);
//         }
    
//         return min(take, nonTake);
//     }

    int solve(int n, int target, int num[], vector<vector<int>> &dp) {
        for(int i = 0; i <= target; i++) {
            if(i % num[0] == 0) dp[0][i] = i / num[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= target; j++) {
                int nonTake = dp[i - 1][j];
                int take = 1e9;
                if(num[i] <= j) take = 1 + dp[i][j - num[i]];

                dp[i][j] = min(take, nonTake);
            }
        }
        return dp[n - 1][target];
    }
	
	int minCoins(int coins[], int M, int V) { 
	    vector<vector<int>> dp(M, vector<int>(V + 1, -1));
        int result = solve(M, V, coins, dp);
        
        if(result >= 1e9) return -1;
        return result;
	} 
	  
};