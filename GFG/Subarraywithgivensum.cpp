// Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s) {
        if(s == 0) return {-1};
        
        long long l = 0, r = 0, sum = arr[0];
        while(r < n) {
            if(sum == s) return {l + 1, r + 1};
            else if(sum < s) {
                r++;
                if(r < n) sum += arr[r];
            } else {
                sum -= arr[l];
                l++;
            }
        }
        return {-1};
    }
};