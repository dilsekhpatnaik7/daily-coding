// Problem Link: https://practice.geeksforgeeks.org/problems/649205908e04ac00f303626fa845261318adfa8f/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
       vector<vector<int>>d;
       for(int i = 0; i < intervals.size(); i++){
           d.push_back({intervals[i][1], intervals[i][0], intervals[i][2]});
       }
       sort(d.begin(), d.end());
       map<int,int>m = {{0,0}};
       for(auto it:d){
           int cur = prev(m.upper_bound(it[1]))->second+it[2];
           if(cur > m.rbegin()->second){
               m[it[0]] = cur;
           }
       }
       return m.rbegin()->second;
    }
};