/*
Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    Node* solve(int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd, map<int, vector<int>>& m) {
        if(preStart > preEnd || inStart >inEnd) return nullptr;

        Node* root = new Node(pre[preStart]);
        
        vector<int>& occurrences = m[root->data];
        int inRoot = occurrences.front();
        occurrences.erase(occurrences.begin());
        int numsLeft = inRoot - inStart;

        root->left = solve(pre, preStart + 1, preStart + numsLeft, in, inStart, inRoot - 1, m);
        root->right = solve(pre, preStart + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, m);

        return root;
    }
    
    Node* buildTree(int in[], int pre[], int n) {
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++) {
            m[in[i]].push_back(i);
        }
        return solve(pre, 0, n - 1, in, 0, n - 1, m);
    }
};