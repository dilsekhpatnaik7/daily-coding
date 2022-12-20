// Problem Link: https://leetcode.com/problems/keys-and-rooms/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& a) {
       int n = a.size();
       vector<bool>check(n,false);
       queue<int>q;
       for(int i=0;i<a[0].size();i++){
           q.push(a[0][i]);
       }
       check[0]=true;
       while(!q.empty()){
           auto x = q.front();
           q.pop();
           check[x]=true;
           for(auto i : a[x]){
               if(!check[i]){
                   q.push(i);
               }
           }
       }
       for(auto i : check)
       if(!i) return false;

       return true;
    }
};