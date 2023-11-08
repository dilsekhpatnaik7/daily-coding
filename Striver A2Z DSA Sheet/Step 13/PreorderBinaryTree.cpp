/*
Problem Link: https://www.codingninjas.com/studio/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int>* root, vector<int>& ans) {
    if(root == NULL) return;

    ans.push_back(root->data);
    solve(root->left, ans);
    solve(root->right, ans);
}

vector<int> preOrder(TreeNode<int> * root){
    vector<int> ans;
    solve(root, ans);
    return ans;
}