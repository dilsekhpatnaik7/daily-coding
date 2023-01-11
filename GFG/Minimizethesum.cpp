// Problem Link: https://practice.geeksforgeeks.org/problems/86e609332c9ef4f6b8aa79db11a6c0808c4a1bca/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        for(int i = 0; i < N; i++) {
            q.push(arr[i]);
        }
        while(q.size() != 1) {
            int sum = 0;
            
            int a = q.top();
            q.pop();
            
            int b = q.top();
            q.pop();

            ans += a + b;
            sum += a+b;
            q.push(sum);
        }
        return ans;
    }
};