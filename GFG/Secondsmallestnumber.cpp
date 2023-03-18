// Problem Link: https://practice.geeksforgeeks.org/problems/5c2734730cb1e98e3877a0b91f7d680d0efc8acf/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{   
public:
    string secondSmallest(int S, int D){
        if(S>D * 9-1) return "-1";
        S = S - 1; 
        int x = D;
        string ans = string(D,'0');
        ans[0]='1';
        for(int i = D - 1; i >= 0; i--) {
            if(S-9 > 0) ans[i]='9';
            else if(i == D - 1) {
                ans[i] += S - 1;
                ans[i - 1] += 1;
                break;  
            }
            else if(S == 9) {
                ans[i] += S - 1;
                ans[i - 1] += 1;
                break;
            }
            else {
                ans[i] += S + 1;
                ans[i + 1] = '8';
                break;
            }
            S = S - 9;
        }
         return ans;
    }
};