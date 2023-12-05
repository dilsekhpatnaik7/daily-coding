// Problem Link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-an-array-of-0s-1s-and-2s

// Dutch National Flag Algorithm which uses 3 pointers.
class Solution {
public:
    void sort012(int a[], int n){
        int t, low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            t = a[mid];
            if(t == 0) swap(a[low++], a[mid++]);
            else if(t == 1) mid++;
            else if(t == 2) swap(a[mid], a[high--]);
        }
    }
};