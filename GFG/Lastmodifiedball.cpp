// Problem Link: https://practice.geeksforgeeks.org/problems/33af95e5935f1f2a0c3f5083c4b9d0db68e97bd4/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    int solve(int N, vector<int> A) {
        N -= 1;
        while(N >= 0){
            if(A[N] < 9) return N + 1;
            else N--;
        }
        return N + 1;
    }
};