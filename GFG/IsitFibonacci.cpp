// Problem Link: https://practice.geeksforgeeks.org/problems/202d95ecdeec659401edc63dd952b1d37b989ab8/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        if(K >= N){
            return GeekNum[N - 1];
        }
        vector<long long> pfsum = GeekNum;
        long long sum = 0;
        for(auto x: GeekNum){
            sum += x;
        }
        pfsum.push_back(sum);
        for(long long i = K + 1; i <= N; i++){
            sum+=pfsum[i - 1];
            sum-=pfsum[i - K - 1];
            pfsum.push_back(sum);
        }
        return pfsum[N - 1];
    }
};