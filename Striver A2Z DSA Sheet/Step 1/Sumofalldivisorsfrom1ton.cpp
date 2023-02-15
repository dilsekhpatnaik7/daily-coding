// Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

class Solution {
public:
    long long sumOfDivisors(int N) {
        long long ans = 0;
        for(int i = 1; i <= N; i++) {
            ans += (N / i) * i;
        }
        return ans;
    }
};