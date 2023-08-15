/*
Problem Link: https://www.codingninjas.com/studio/problems/anagram-pairs_626517?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Cmplexity: O(N)
*/

#include<bits/stdc++.h>
bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) return false;

    unordered_map<char, int> count;
    int n = str1.length();
    for(int i = 0; i < n; i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    for(int i = 0; i < n; i++) {
        if(count[str1[i]] != 0) return false;
    }
    return true;
}