// Problem Link: https://practice.geeksforgeeks.org/problems/5a7e1a52f1b7796238f9efea4c6fda389f26c327/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int solve(int a, int b) {
        if(a == b) return 0;
        if((a & b) == min(a, b)) return 1;
        return 2;
    }
};