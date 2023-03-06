// Problem Link: https://practice.geeksforgeeks.org/problems/07e45fe40846bc670ad2507d2c649304699768b9/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int noConseBits(int n) {
        int count = 0;
        for(int i = 31; i >= 0; i--) {
            if(n & (1 << i)) count++;
            else count = 0;
            if(count == 3) {
                n = n & (~(1 << i));
                count = 0;
            }
        }
        return n;
    }
};