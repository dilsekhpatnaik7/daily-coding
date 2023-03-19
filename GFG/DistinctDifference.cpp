// Problem Link: https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        set<int> ls, rs;
        vector<int > lft(N),rgt(N),ans(N);
        
        for(int i = 0; i < N; i++) {
            lft[i] = ls.size();
            ls.insert(A[i]);
            rgt[N - i - 1] = rs.size();
            rs.insert(A[N - i - 1]);
        }
        
        for(int i = 0; i < N; i++) {
            ans[i] = lft[i] - rgt[i];
        }
        return ans;
    }
};