/*
Problem Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1

Time Complexity: O(N)
Space Cmplexity: O(1)
*/

class Solution{
  public:
    int atoi(string str) {
        int n = str.length(), i = 0;
        while(i < n && str[i] == ' ') i++;
        int positive = 0, negative = 0;
        if(str[i] == '+') {
            positive++;
            i++;
        }
        if(str[i] == '-') {
            negative++;
            i++;
        }
        double ans = 0;
        while(i < n) {
            if(str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + (str[i] - '0');
            } else {
                return -1;
            }
            i++;
        }
        if(negative > 0) ans = -1 * ans;
        if(positive > 0 && negative > 0) return 0;
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        
        return (int)ans;
    }
};