// Problem Link: https://practice.geeksforgeeks.org/problems/e0059183c88ab680b2f73f7d809fb8056fe9dc43/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        long long ans = 0;
        vector<int> rem(k);
        for(int i = 0; i < n; i++){
            ans += rem[arr[i] % k]++;
        }
        return ans;
    }
};