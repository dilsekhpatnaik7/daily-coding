// Problem Link: https://practice.geeksforgeeks.org/problems/6e63df6d2ebdf6408a9b364128bb1123b5b13450/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        sort(arr.begin(), arr.end());
        long long ans = 0;
        set<long long> st;
        
        for(long long a : arr) {
            auto pos = st.find(a);
            if(st.find(a) != st.end()) {
                long long val = *st.rbegin() + 1;
                ans += (val-a);
                a = val;
            }
            st.insert(a);
        }
        return ans;
    }
};