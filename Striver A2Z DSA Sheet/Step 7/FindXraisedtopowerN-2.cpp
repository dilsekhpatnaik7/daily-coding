/*
Problem Link: https://www.codingninjas.com/studio/problems/find-x-raised-to-power-n-_626560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(log(N))
Space Complexity: O(log(N))
*/

double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n < 0) {
        n = abs(n);
        x = 1 / x;
    }
    if(n % 2 == 0) return myPow(x * x, n / 2);
    else return x * myPow(x, n - 1);
}