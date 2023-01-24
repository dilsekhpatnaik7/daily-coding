// Problem Link: https://practice.geeksforgeeks.org/problems/95080eb9efbf7cc5cb4851ddf8d7946e3f212a49/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        for(int i = n/2; i >= 0; i--){
            string front = s.substr(0,i+1);
            string back = s.substr(i+1,i+1);
            if(front == back) return n-i;
        }
        return n;
    }
};