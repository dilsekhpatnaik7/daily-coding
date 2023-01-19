// Problem Link: https://practice.geeksforgeeks.org/problems/230d87552a332a2970b2092451334a007f2b0eec/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int a = 0, b = 0, c= 0, d = 0;
        while(A > C || A > D){
            if(A > C) a++;
            if(A > D) b++;
            A /= 2;
        }
        while(B > C || B > D){
            if(B > C) c++;
            if(B > D) d++;
            B /= 2;
        }
        return min((a + d), (b + c));
    }
};