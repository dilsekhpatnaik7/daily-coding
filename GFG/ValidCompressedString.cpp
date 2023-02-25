// Problem Link: https://practice.geeksforgeeks.org/problems/13eb74f1c80bc67d526a69b8276f6cad1b8c3401/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int checkCompressed(string S, string T) {
        int i = 0, j = 0;
        while(i < S.size() && j < T.size()) {
            if(isdigit(T[j])) {
                int count = 0;
                while(j < T.size() && isdigit(T[j])) {
                    count = count * 10 + (T[j] - '0');
                    j++;
                }
                i += count;
            }
            else if(S[i] == T[j]) {
                i++;
                j++;
            }
            else if(S[i] != T[j]) return 0;
        }
        return (i == S.size()) && (j == T.size());
    }
};