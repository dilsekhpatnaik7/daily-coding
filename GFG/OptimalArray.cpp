// Problem Link: https://practice.geeksforgeeks.org/problems/d4aeef538e6dd3280dda5f8ed7964727fdc7075f/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> ans(n, 0);
        int i = 1;
        while(i < n) {
            ans[i] = ans[i - 1] + (a[i] - a[i / 2]);
            i++;
        }
        return ans;
    }
};