// Problem Link: https://practice.geeksforgeeks.org/problems/214734e358208c1c6811d9b237b518f6b3c3c094/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans;
        stack<long long> s;
        for(int i = n - 1; i >= 0; i--){
            if(s.size() == 0) ans.push_back(-1);
            else if(s.size() > 0 && s.top() > arr[i]) ans.push_back(s.top());
            else if(s.size() > 0 && s.top() <= arr[i]){
                while(s.size() > 0 && s.top() <= arr[i]){
                    s.pop();
                }
                if(s.size() == 0) ans.push_back(-1);
                else ans.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};