// Problem Link: https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 2; i < n; i++){
            int take = arr[i] + dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
	}
};