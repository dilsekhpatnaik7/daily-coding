// Problem Link: https://leetcode.com/problems/daily-temperatures/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size());
        stack<int>st;
        st.push(temp.size()-1);
        ans[temp.size()-1]=0;
        for(int i=temp.size()-2;i>=0;i--){
           while(!st.empty()&& temp[i]>=temp[st.top()]){
               st.pop();
           }
           if(!st.empty()){
               ans[i]=st.top()-i;
           }
           else 
              ans[i]=0;
           st.push(i);
        }
        return ans;
    }
};