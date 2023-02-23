// Problem Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=majority-element

// Moore Voting Alogorithm GFG
class Solution {
public:
    int majorityElement(int a[], int size) {
        int count = 0, candidate = 0;
        for(int i = 0; i < size; i++){
            if(count == 0) candidate = a[i];
            if(candidate == a[i]) count++;
            else count--;
        }
        count = 0;
        for(int i = 0; i < size; i++) {
            if(candidate == a[i]) count++;
        }
        return count > size /2 ? candidate : -1;
    }
};