// Problem Link: https://practice.geeksforgeeks.org/problems/4dfa8ba14d4c94f4d7637b6b5246782412f3aeb8/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int maxLength(vector<int> &arr,int n){
        int ans = 0;
        int neg = -2, zero = -1, sign = 1;
        for(int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zero = i;
                sign = 1;
            }
            else if (arr[i] < 0) {
                if (neg < zero)
                    neg = i;
                sign *= -1;
            }
            if (sign > 0) 
                ans = max(ans, i-zero);
            else 
                ans = max(ans, i-neg);
        }
        return ans;
    }
};