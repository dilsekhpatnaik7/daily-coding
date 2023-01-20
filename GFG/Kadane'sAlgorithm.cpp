// Problem Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&category[]=Dynamic%20Programming&curated[]=1&sortBy=submissions
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        // Kadane's Algorithm
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};