/*
Problem Link: https://practice.geeksforgeeks.org/problems/anagram-1587115620/1

Time Complexity: O(N)
Space Cmplexity: O(N)
*/

class Solution {
    public:
    bool isAnagram(string a, string b){
        if(a.length() != b.length()) return false;

        unordered_map<char, int> count;
        int n = a.length();
        for(int i = 0; i < n; i++) {
            count[a[i]]++;
            count[b[i]]--;
        }
        for(int i = 0; i < n; i++) {
            if(count[a[i]] != 0) return false;
        }
        return true;
    }

};