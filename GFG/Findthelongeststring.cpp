// Problem Link: https://practice.geeksforgeeks.org/problems/8d157f11af5416087251513cfc38ffc4d23be308/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        unordered_set<string>st(words.begin(), words.end());
        string ans = "";
        for(auto w: words){
            int i = 1;
            for(i = 1;i < w.size(); i++){
                if(st.count(w.substr(0,i)) == 0)break;
                
            }
            if(i == w.size()){
                if(w.size() > ans.size())ans = w;
                if(w.size() == ans.size())ans = min(ans,w);
            }
        }
       
        return ans;
    }
};