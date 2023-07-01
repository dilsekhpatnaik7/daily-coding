// Problem Link: https://practice.geeksforgeeks.org/problems/set-bits0143/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int setBits(int N) {
        return __builtin_popcount(N);
    }
};