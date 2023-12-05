// Problem Link: https://practice.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=who-will-win

class Solution{
public:
    int searchInSorted(int arr[], int N, int K) {
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == K) return 1;
            else if(K > arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};