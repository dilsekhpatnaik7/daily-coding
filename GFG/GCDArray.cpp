// Problem Link: https://practice.geeksforgeeks.org/problems/2b70d42632a4e207569c6d2d777383e4603d6fe1/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int solve(int N, int K, vector<int> &arr) {
        int sum = 0;
        for(int i = 1; i < N; i++){
            arr[i] += arr[i-1];
        }
        sum = arr[N-1];
        vector<int> factors;
        for(int i = 1; i*i <= sum; i++){
            if(sum%i == 0){
                factors.push_back(i);
                if(i != sum/i)
                factors.push_back(sum/i);
            }
        }
        sort(factors.begin(), factors.end(), greater<int>{});
        int ans = 1; 
        for(auto it:factors){
            int count = 0;
            for(int i = 0; i < N; i++){
                if(arr[i]%it==0) count++;
            }
            if(count >= K){
                ans = it;
                break;
            }
        }
        return ans;
    }
};