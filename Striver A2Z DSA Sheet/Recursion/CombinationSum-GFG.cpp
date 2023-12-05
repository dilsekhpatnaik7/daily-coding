/*
Problem Link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N + N + N ^ 2)
*/

class Solution {
    public:
    void findCombinations(int index, vector<int>& A, int sum, vector<int>& temp, vector<vector<int>>& ans) {
        if(index >= A.size()) {
            if(sum == 0) {
                ans.push_back(temp);
            }
            return;
        }
        
        if(A[index] <= sum) {
            temp.push_back(A[index]);
            findCombinations(index, A, sum - A[index], temp, ans);
            temp.pop_back();
        }
        findCombinations(index + 1, A, sum, temp, ans);
    }
    
    vector<int> removeRepeated(vector<int>& A){
        int n = A.size();
        vector<int> unq;
        unordered_map<int, int> m;
    
        for(int i = 0;i < n; i++){
            m[A[i]]++;
        }
        for(auto j: m){
            unq.push_back(j.first);
        }
        return unq;
    }

    
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        A = removeRepeated(A);
        sort(A.begin(), A.end());
        findCombinations(0, A, B, temp, ans);
        return ans;
    }
};