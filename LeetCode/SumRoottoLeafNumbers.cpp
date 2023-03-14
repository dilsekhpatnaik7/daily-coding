// Problem Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

// Iterative Approach Using Stack
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;      
        s.push({root, 0});
        int sum = 0;
        while(!s.empty()) {
            auto [root, cur] = s.top(); s.pop();
            cur = cur * 10 + root -> val;
            if(!root -> left && !root -> right) sum += cur;
            if(root -> right) s.push({root -> right, cur});
            if(root -> left) s.push({root -> left, cur});
        }
        return sum;
    }
};

// Recursive Approach Using PreOrder Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cur) {
        if(!root) return 0;
        cur = cur * 10 + root -> val;             
        if(!root -> left && !root -> right) return cur;
        return dfs(root -> left, cur) + dfs(root -> right, cur); 
    }  
};