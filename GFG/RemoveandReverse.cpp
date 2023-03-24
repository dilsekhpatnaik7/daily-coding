// Problem Link: https://practice.geeksforgeeks.org/problems/1e2f365be6114b671b915e145ec7dbcfdc432910/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    string removeReverse(string S) {
        int i = 0, j = S.length() - 1;
        int map[26]; 
        fill(map, map+26, 0);
        bool flag = true;
        int cnt = 0;

        for(char ch: S) map[ch-'a']++;

        string begin="", end="";
        while(i <= j) {
            char ch;
            if(flag) ch = S[i++];
            else ch = S[j--];

            if(map[ch - 'a'] > 1) {
                map[ch - 'a']--;
                cnt++;
                flag = !flag;
            }
            else {
                if(flag) begin += ch;
                else end = ch + end;
            }
        }
        string ans = begin + end;
        if(cnt % 2 == 1) reverse(ans.begin(), ans.end());
        return ans;
    }
};