// Problem Link: https://practice.geeksforgeeks.org/problems/466faca80c3e86f13880710491c634d26abd44a7/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    string removePair(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(ans.size() == 0 || ans.back() != s[i]) ans += s[i];
            else ans.pop_back();
        }
        if(ans.size()) return ans;
        return "-1";
    }
};