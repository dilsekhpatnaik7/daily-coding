// Problem Link: https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximize-number-of-1s
/*
    Same as Problem Apple Sequences 
    Problem Link: https://practice.geeksforgeeks.org/problems/38f100615d0b2efa755e7b07f905e0f8cd2fe5df/1
*/
class Solution{
public:
    int findZeroes(int arr[], int n, int m) {
        int start = 0, end = 0, ans = 0;
        while(end != n) {
            if(m > 0) {
                if(arr[end] == 0) m--;
            }
            else {
                if(arr[end] == 0) {
                    while(arr[start] != 0) {
                        start++;
                    }
                    start++;
                }
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }  
};