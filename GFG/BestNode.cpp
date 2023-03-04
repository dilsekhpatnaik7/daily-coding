// Problem Link: https://practice.geeksforgeeks.org/problems/a3493283697b7b69573a840f371a55ccd9332bb0/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

class Solution {
private:
    long long ans = INT_MIN;
    vector<int> nums;
public:
    long long find(){
        if(nums.size() == 1){
            return nums[0];
        }
        long long res = INT_MIN;
        long long sum1 = nums[nums.size()-2];
        long long sum2 = nums[nums.size()-1];
        res=max(res, sum2);
        res=max(res, sum1-sum2);
        int i=nums.size() - 3;
        while(i >= 0){
            sum2 += nums[i];
            i--;
            res=max(res,sum2-sum1);
            if(i<0){
                break;
            }
            sum1 += nums[i--];
            res = max(res,sum1-sum2);
        }
        return res;
        
    }
    
    void solve(int src, vector<int> adj[], vector<int> &a){
        nums.push_back(a[src]);
        bool isLeaf = true;
        for(auto x: adj[src]){
            isLeaf = false;
            solve(x,adj,a);
        }
        if(isLeaf){
            ans = max(ans,find());
        }
        nums.pop_back();
    }
    
    long long bestNode(int N, vector<int> &a, vector<int> &p) {
        vector<int> adj[N];
        
        for(int i = 0; i < N; i++){
            if(p[i] == -1){
                continue;
            }
            adj[p[i]-1].push_back(i);
        }
        solve(0,adj,a);
        return ans;
    }
};