// Problem Link: https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        long long gcd = __gcd(A, B);
        ans.push_back((A * B) / gcd);
        ans.push_back(gcd);
        return ans;
    }
};