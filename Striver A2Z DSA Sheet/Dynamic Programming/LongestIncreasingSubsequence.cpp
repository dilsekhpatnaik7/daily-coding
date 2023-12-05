/*
Problem Link: https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        if(arr[i] > temp.back()) temp.push_back(arr[i]);
        else {
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }
    return temp.size();
}
