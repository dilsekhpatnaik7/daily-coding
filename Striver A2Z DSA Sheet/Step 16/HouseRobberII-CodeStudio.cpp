/*
Problem Link: https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h> 
long long int solve(long long int index, vector<long long int>& v, vector<long long int>& dp) {
    if(index == 0) return v[index];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];

    long long int left = v[index] + solve(index - 2, v, dp);
    long long int right = 0 + solve(index - 1, v, dp);

    return dp[index] = max(left, right);
}

long long int houseRobber(vector<int>& valueInHouse) {
    if(valueInHouse.size() == 1) return valueInHouse[0];

    vector<long long int> temp1, temp2;
    for(long long int i = 0; i < valueInHouse.size(); i++) {
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != valueInHouse.size() - 1) temp2.push_back(valueInHouse[i]);
    }

    long long int n = temp1.size(), m = temp2.size();
    vector<long long int> dp1(n, -1), dp2(m, -1);
    long long int left = solve(n - 1, temp1, dp1);
    long long int right = solve(m - 1, temp2, dp2);

    return max(left, right);
}