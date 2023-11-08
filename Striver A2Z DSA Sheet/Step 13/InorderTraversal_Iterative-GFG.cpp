/*
Problem Link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    void solve(Node* root, vector<int>& ans) {
        stack<Node*> s;
        Node* node = root;

        while(true) {
            if(node) {
                s.push(node);
                node = node->left;
            } else {
                if(s.empty()) break;
                node = s.top();
                s.pop();

                ans.push_back(node->data);
                node = node->right;
            }
        }
    }
  
    vector<int> inOrder(Node* root) {
        if(!root) return {};

        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};