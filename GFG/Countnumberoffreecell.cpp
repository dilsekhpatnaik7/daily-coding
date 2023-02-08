// Problem Link: https://practice.geeksforgeeks.org/problems/90a81c305b1fe939b9230a67824749ceaa493eab/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long> ans;
      long long fc = 1LL*n*n;
      unordered_set<int> r,c;
      for(int i = 0; i < k ;i++){
          if(r.find(arr[i][0]) == r.end()){
              r.insert(arr[i][0]);
              fc -= (n-c.size());
          }
          if(c.find(arr[i][1]) == c.end()){
              c.insert(arr[i][1]);
              fc -= (n-r.size());
          }
          ans.push_back(fc);
      }
      return ans;
    }
};