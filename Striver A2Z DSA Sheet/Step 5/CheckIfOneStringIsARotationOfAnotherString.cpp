/*
Problem Link: https://www.codingninjas.com/studio/problems/check-if-one-string-is-a-rotation-of-another-string_1115683?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

#include<bits/stdc++.h>

int isCyclicRotation(string &p, string &q) {
    return p.size() == q.size() && (p + p).find(q) != string::npos;
}