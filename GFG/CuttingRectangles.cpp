// Problem Link: https://practice.geeksforgeeks.org/problems/a7a4da81b20f4a05bbd93f5786fcf7478298f4f5/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    vector<long long int> minimumSquares(long long int L, long long int B) {
        long long K = __gcd(L, B);
        long long N = (L / K) * (B / K);
        return {N, K};
    }
};