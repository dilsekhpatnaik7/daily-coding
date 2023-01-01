// Problem Link: https://leetcode.com/problems/word-pattern/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> s_word;
        int i=0;
        for(int k=0;k<s.size();k++)
        {
            if(s[k]==' ')
            {
                s_word.push_back(s.substr(i,k-i));
                i=k+1;
            }
        }
        s_word.push_back(s.substr(i,s.size()));
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        if(pattern.size()!=s_word.size()) return false;
        for(int i=0;i<pattern.size();i++)
        {
            if((mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=s_word[i]) || (mp2.find(s_word[i])!=mp2.end() && mp2[s_word[i]]!=pattern[i])) return false;
            else{
                mp1[pattern[i]]=s_word[i];
                mp2[s_word[i]]=pattern[i];
            }
        }
        return true;
    }
};