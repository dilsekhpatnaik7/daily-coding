// Problem Link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/0?company[]=Visa&company[]=Visa&page=2&query=company[]Visapage2company[]Visa&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=kadanes-algorithm

// Kadane's Algorithm
class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};