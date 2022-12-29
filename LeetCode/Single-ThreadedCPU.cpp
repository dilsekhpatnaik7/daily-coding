// Problem Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       int n = tasks.size();
        for(int i = 0; i <n ; i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        
        int i = 0;
        long long t = tasks[0][0];
        
        while(!pq.empty() or i<n){
            while(i<n && t>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
           
            if(pq.empty()){
                t = tasks[i][0];
            }
            else{
               pair<int,int> p = pq.top();
               pq.pop();
               ans.push_back(p.second);
               t += p.first; 
            }  
        }
        return ans;
    }
};