// Problem Link: https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int low = 0, high = n - 1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(arr[mid] == k) return mid;
            else if(k > arr[mid]) low = mid + 1;
            else high = mid - 1; 
        }
        return -1;
    }
};