// Problem Link: https://practice.geeksforgeeks.org/problems/38f100615d0b2efa755e7b07f905e0f8cd2fe5df/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {   
public:
    int appleSequences(int n, int m, string arr) {
        int start = 0, end = 0, ans = 0;
        while(end != n) {
            if(m > 0) {
                if(arr[end] == 'O') m--;
            }
            else {
                if(arr[end] == 'O') {
                    while(arr[start] != 'O') {
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