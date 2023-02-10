// Problem Link: https://practice.geeksforgeeks.org/problems/45fa306a9116332ece4cecdaedf50f140bd252d4/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    int maxInstance(string s){
        vector<int>v;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'||s[i]=='a'||s[i]=='l'||s[i]=='o'||s[i]=='n'){
                m[s[i]]++;
            }
        }
        m['l'] = m['l']/2;
        m['o'] = m['o']/2;
        v.push_back(m['b']);
        v.push_back(m['l']);
        v.push_back(m['o']);
        v.push_back(m['n']);

        return *min_element(v.begin(),v.end());
    }
};