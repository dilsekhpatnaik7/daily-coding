// Problem Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicate-elements-from-sorted-array

class Solution {
public:
    int remove_duplicate(int a[],int n) {
        int k = 1;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[i - 1]) {
                a[k] = a[i];
                k++;
            }
        }
        return k;
    }
};