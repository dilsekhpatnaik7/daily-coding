// Problem Link: https://practice.geeksforgeeks.org/problems/f4d22b1f9d62e8bee0ff84e9fa51dc66eb5005ec/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
        int n = S.size(), m = P.size(), j = 0;
        for(int i = 0; i < n; i++) {
            if((i+1 < n) && (S[i] != '?') && (S[i]==S[i+1])) {
                while((j < m) && (i+1 < n) && (S[i] == S[i+1])) {
                    S[P[j]] = '?';
                    j++;
                }
            }
        }
        return j;
    }
};