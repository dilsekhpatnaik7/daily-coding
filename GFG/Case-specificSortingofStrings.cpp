// Problem Link: https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    string caseSort(string str, int n) {
        int j = 0, k = 0;
        string low = "", upper="";
        for(int i=0;i<n;i++) {
            if(str[i] >= 97 && str[i] <= 122) low += str[i];
             else upper += str[i];
        }
        sort(low.begin(), low.end());
        sort(upper.begin(), upper.end());

        for(int i = 0; i < n; i++) {
            if(str[i] >= 97 && str[i] <= 122) {
                str[i] = low[j];
                j++;
            }
            else {
                str[i] = upper[k];
                k++;
            }
        }
        return str;
    }
};