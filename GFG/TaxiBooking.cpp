// Problem Link: https://practice.geeksforgeeks.org/problems/7995e41d167d81f14f1d4194b29ef839f52d18ba/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int ans = INT_MAX;
        for(int i = 0; i < N; i++){
            ans = min(ans, abs((cur - pos[i]) * time[i]));
        }
        return ans;
    }
};