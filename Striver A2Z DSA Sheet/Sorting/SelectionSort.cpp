// Problem Link: https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort
/*
    General approach is to selct the minimum number ans swap with the current number.
    Bringing smaller elements to front.
*/
class Solution {
public:
    int select(int arr[], int i, int n){
        int index = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[index]) {
                index = j;
            }
        }
        return index;
    }
     
    void selectionSort(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            swap(arr[i], arr[select(arr, i, n)]);
        }
    }
};