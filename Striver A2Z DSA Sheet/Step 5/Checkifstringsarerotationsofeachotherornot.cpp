/*
Problem Link: https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution {
    public:
    bool areRotations(string s1,string s2) {
        queue<char> q1, q2;
        for(int i = 0; i < s1.size(); i++) {
            q1.push(s1[i]);
        }
        for(int i = 0; i < s2.size(); i++) {
            q2.push(s2[i]);
        }

        int k = s2.size();
        while(k) {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if(q1 == q2) return true;
            k--;
        }
        return false;
    }
};