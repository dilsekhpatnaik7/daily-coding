/*
Problem Link: https://leetcode.com/problems/count-good-numbers/

Time Complexity: O(log(N))
Space Cmplexity: O(log(N))
*/

class Solution {
public:
    long long myPow(long long x, long long n,int mod) {
        if(n==0) return 1;
        if(n%2==0) return myPow((x*x)%mod,n/2,mod)%mod;
        else return x*myPow(x,n-1,mod) %mod;
    }
    
    long long countGoodNumbers(long long n) {
        int mod = 1e9+7;
        long long four = n/2;
        long long five =n/2+n%2;
        
        return (myPow(5,five,mod) * myPow(4,four,mod))%mod;
    }
};