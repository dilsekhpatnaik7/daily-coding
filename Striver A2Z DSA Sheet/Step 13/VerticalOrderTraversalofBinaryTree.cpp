/*
Problem Link: https://www.codingninjas.com/studio/problems/vertical-order-traversal_3622711?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, vector<int>& ans) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode<int>* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->data);
        
        if(node->left) q.push({node->left, {x - 1, y + 1}});
        if(node->right) q.push({node->right, {x + 1, y + 1}});
    }

    for(auto p: nodes) {
        for(auto qq: p.second) {
            ans.insert(ans.end(), qq.second.begin(), qq.second.end());
        }
    }
}

vector<int> verticalOrderTraversal(TreeNode<int> *root) {
    if(!root) return {};
        
    vector<int> ans;
    solve(root, ans);
    return ans;
}