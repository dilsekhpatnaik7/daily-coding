// Problem Link: https://leetcode.com/problems/string-compression/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1, n = chars.size();
        string ans;
        ans.push_back(chars[0]);
        for(int i = 1; i < n; i++) {
            if(chars[i] == chars[i - 1]) count++;
            else {
                if(count > 1) {
                    ans += to_string(count);
                    count = 1;
                }
                ans += chars[i];
            }
        }
        if(count > 1) ans += to_string(count);
        for(int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }
        return ans.size();
    }
};