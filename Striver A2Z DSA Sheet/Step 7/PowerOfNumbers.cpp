/*
Problem Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1

Time Complexity: O(log(N))
Space Cmplexity: O(log(N))
*/

class Solution{
    public:
    int mod = 1000000007;
    
    long long powered(int N, int R) {
        if(R == 1) return N;
        if(R == 0) return 1;
        long ans = power(N, R / 2) % mod;
        if(R % 2 == 0){
            return (ans*ans)%mod;
        } else {
            return (((ans*ans)%mod)*N)%mod;
        }
    }
    
    long long power(int N,int R) {
        return powered(N, R);
    }

};