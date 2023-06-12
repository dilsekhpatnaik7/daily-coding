// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?company[]=Synopsys&company[]=Synopsys&page=1&query=company[]Synopsyspage1company[]Synopsys&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-two-sorted-arrays

class Solution{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = 0, j = 0, k = 0;
        int res[n+m];
        
        while(i < n && j < m){
            if(arr1[i] < arr2[j]) {
                res[k++] = arr1[i++];
            }
            else {
                res[k++] = arr2[j++];
            }
        }
        while(i < n) {
            res[k++] = arr1[i++];
        }
        while(j<m) {
            res[k++] = arr2[j++];
        }
        int index1 = 0;
        int index2 = n;
        for(int i = 0; i < n; i++){
           arr1[i] = res[index1++];
        }
        for(int i = 0; i < m; i++){
            arr2[i] = res[index2++];
        }
    } 
};