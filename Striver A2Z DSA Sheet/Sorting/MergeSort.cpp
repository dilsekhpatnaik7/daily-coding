// Problem Link: https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
/*
    Uses Divide and Conquer Algorothm, diving and mergong the subarrays.
*/
class Solution {
    public:
    void merge(int arr[], int l, int m, int r) {
        int left = l, right = m + 1, i = 0, temp[r - l + 1];
        while(left <= m && right <= r) {
            if(arr[left] <= arr[right]) temp[i++] = arr[left++];
            else temp[i++] = arr[right++];
        }
        while(left <= m) {
            temp[i++] = arr[left++];
        }
        while(right <= r) {
            temp[i++] = arr[right++];
        }
        for(i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    void mergeSort(int arr[], int l, int r) {
        if(l == r) return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid ,r);
    }
};