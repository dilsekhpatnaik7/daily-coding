// Problem Link: https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
int binarySearch(vector<int>& arr, int low, int high) {
    int ans = INT_MAX, index = -1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(arr[low] <= arr[high]) {
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
                break;
            }
        }

        if(arr[low] <= arr[mid]) {
            if(arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        } else {
            if(arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int findKRotation(vector<int> &arr){
    return binsrySearch(arr, 0, arr.size() - 1);   
}