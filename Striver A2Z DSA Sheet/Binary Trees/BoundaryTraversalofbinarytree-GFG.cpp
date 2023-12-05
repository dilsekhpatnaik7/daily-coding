/*
Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isLeaf(Node* root) {
        return root && (!root->left && !root->right);
    }

    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* node = root->left;
        
        while(node) {
            if(!isLeaf(node)) ans.push_back(node->data);
            if(node->left) node = node->left;
            else if(node->right) node = node->right;
            else break;
        }
    }
    
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* node = root->right;
        vector<int> t;
        
        while(node) {
            if(!isLeaf(node)) t.push_back(node->data);
            if(node->right) node = node->right;
            else if(node->left) node = node->left;
            else break;
        }
        for(int i = t.size() - 1; i >= 0; i--) {
            ans.push_back(t[i]);
        }
    }
    
    void addLeaf(Node* root, vector<int>& ans) {
        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        if(root->left) addLeaf(root->left, ans);
        if(root->right) addLeaf(root->right, ans);
    }

    vector<int> boundary(Node *root) {
        if(!root) return {};
        
        vector<int> ans; 
        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeftBoundary(root, ans);
        addLeaf(root, ans);
        addRightBoundary(root, ans);
        
        return ans;
    }
};