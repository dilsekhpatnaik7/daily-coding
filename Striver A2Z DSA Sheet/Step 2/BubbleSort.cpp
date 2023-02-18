// Problem Link: https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
/*
    General approach is to send the greater elememts at the back by swappimg with the current element.
*/
class Solution {
public:
    void bubbleSort(int arr[], int n) { 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(arr[i] > arr[j]) {
                    int t = arr[i];
                    arr[i] = arr[j];
                    arr[j] = t;
                }
            }
        }
    }
};