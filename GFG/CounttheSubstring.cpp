// Problem Link: https://practice.geeksforgeeks.org/problems/f72994353d123b925ff20f0694b662191df03ea2/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
  long long countSubstring(string S){
    int cnt=0;
    long long int ans = 0;
    int n = S.size();
    vector<long long int> freq(2*n+2,0);
    vector<long long int> dp(2*n+2,0);
    freq[n]++;
    for(char c:S) {
        if(c=='0')
            cnt--;
        else
            cnt++;
        
        if(cnt - 1 + n >= 0)
            dp[cnt + n] = dp[cnt - 1 + n] + freq[cnt - 1 + n];
            
        ans += dp[cnt + n];
        freq[cnt + n]++;
    }
    return ans;
  }
};