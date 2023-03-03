// Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

// 1st Approach using KMP Algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0)  return 0;
        vector<int> pi(m);
        pi[0] = 0;
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && needle[j] != needle[i]) {
                j = pi[j - 1];
            }
            if (needle[j] == needle[i]) {
                j++;
            }
            pi[i] = j;
        }
        j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = pi[j - 1];
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};

// 2nd Approach using in-built function find()
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        return pos;
    }
};