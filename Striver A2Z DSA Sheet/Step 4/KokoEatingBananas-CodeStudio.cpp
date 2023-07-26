// Problem Link: https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include<bits/stdc++.h>
int findMax(vector<int>& v) {
    int maximum = INT_MIN;
    for(auto i: v) {
        maximum = max(maximum, i);
    }
    return maximum;
}

bool calculateTotalHours(vector<int>& v, long long mid, int h) {
    if(mid == 0) return 0;
    long long totalHours = 0, n = v.size();
    for(int i = 0; i < n; i++) {
        totalHours += (v[i] + mid - 1) / mid;
        if(totalHours > h) return false;
    }
    return true;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 0, high = findMax(v);
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        bool totalHours = calculateTotalHours(v, mid, h);
        if(totalHours) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}