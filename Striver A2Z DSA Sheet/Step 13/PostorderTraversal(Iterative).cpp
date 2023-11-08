/*
Problem Link: https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution{
    public:
    void solve(Node* root, vector<int>& ans) {
        Node* node = root;

        stack<Node*> s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            node = s1.top();
            s1.pop();
            s2.push(node);

            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }

        while(!s2.empty()) {
            ans.push_back(s2.top()->data);
            s2.pop();
        }
    }
    
    vector<int> postOrder(Node* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};