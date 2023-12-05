/*
Problem Link: https://practice.geeksforgeeks.org/problems/count-good-numbers/1?page=1&sortBy=newest&query=page1sortBynewest

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
    
    int countGoodNumbers(long long N) {
        int mod = 1e9+7;
        long long four = N/2;
        long long five =N/2+N%2;

        return (myPow(5,five,mod) * myPow(4,four,mod))%mod;
    }
};