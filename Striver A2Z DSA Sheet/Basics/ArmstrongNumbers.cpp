// Problem Link: https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1

class Solution {
public:
    int sendCube(int n){
        return n*n*n;
    }
    string armstrongNumber(int n){
        int ans = 0, temp = n;
        while(n != 0){
            int d = n % 10;
            ans += sendCube(d);
            n /= 10;
        }
        return ans == temp ? "Yes" : "No";
    }
};