/*
Problem Link: https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
        int n;
        cin >> n;
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i < n + 1; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[n];
}