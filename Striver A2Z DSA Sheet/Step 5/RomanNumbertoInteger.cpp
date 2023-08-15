/*
Problem Link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        for(int i = 0; i < str.length(); i++){
            if(m[str[i]] < m[str[i + 1]] && i < str.length()) ans -= m[str[i]];
            else ans += m[str[i]];
        }
        return ans;
    }
};