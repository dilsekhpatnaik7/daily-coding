// Problem Link: https://practice.geeksforgeeks.org/problems/fda70097eb2895ecfff269849b6a8aace441947c/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int minRepeats(string A, string B) {
        string rep = A;
        int cnt = 1;
        while(A.size() < B.size()){
            A += rep;
            cnt++;
        }
        if(A.find(B) != -1) return cnt;
        A += rep;
        cnt++;
        if(A.find(B) != -1) return cnt;
        return -1;
    }
};