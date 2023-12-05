// Problem Link: https://practice.geeksforgeeks.org/problems/count-digits5716/1

class Solution{
public:
    int evenlyDivides(int N){
        int temp = N, cnt = 0, rev;
        while(temp != 0){
            rev = temp%10;
            temp /= 10;
            if(rev!=0 && N%rev==0) cnt++;
        }
        return  cnt;
    }
};