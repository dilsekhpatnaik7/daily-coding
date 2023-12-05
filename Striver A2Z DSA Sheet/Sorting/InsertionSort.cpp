// Problem Link: https://practice.geeksforgeeks.org/problems/insertion-sort/0?category[]=Algorithms&page=1&query=category[]Algorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort
/*
    General Approach is to sort the array partially till each index by inserting elements.
*/
class Solution {
    public:
    void insert(int arr[], int i) {
        int j = i - 1, currentElement = arr[i];
        while(j >=0 && arr[j] > currentElement) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentElement;
    }
    
    void insertionSort(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            insert(arr, i);
        }
    }
};