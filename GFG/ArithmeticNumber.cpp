// Problem Link: https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(C==0)
            return A==B;
       return (B-A)%C==0 && (B-A)/C>=0;
    }
};