// Problem Link: https://practice.geeksforgeeks.org/problems/2145720aebf8ea0b07f76b17217b3353a0fbea7f/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        return max(x - 1, N - x) + max(y - 1, M - y);
    }
};