/*
Problem Link: https://practice.geeksforgeeks.org/problems/inorder-traversal/1?utm_source=youtube&utm_medium=collab_fraz_websitelink&utm_campaign=inorder-traversal

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        if(!root) return {};
        
        vector<int> ans;
        Node* node = root;
        while(node) {
            if(!node->left) {
                ans.push_back(node->data);
                node = node->right;
            } 
            else {
                Node* prev = node->left;
                while(prev->right && prev->right != node) {
                    prev = prev->right;
                }

                if(!prev->right) {
                    prev->right = node;
                    node = node->left;
                } else {
                    prev->right = NULL;
                    ans.push_back(node->data);
                    node = node->right;
                }
            }
        }
        return ans;
    }
};