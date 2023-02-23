// Problem Link: https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category=&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays

class Solution{
public:
    long long pairWithMaxSum(long long arr[], long long N) {
        long long int sum = 0, res = INT_MIN;
        for(long long i = 0; i < N - 1; i++){
            sum = arr[i] + arr[i + 1];
            res = max(res, sum);
        }
        return res;
    }
};