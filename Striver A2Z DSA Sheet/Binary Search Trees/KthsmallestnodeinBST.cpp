/*
Problem Link: https://www.codingninjas.com/studio/problems/kth-smallest-node-in-bst_920441?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(log(N))
Space Complexity: O(N)
*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void solve(TreeNode<int>* root, int k, int& count, int& ans) {
    if(!root) return;

    solve(root->left, k, count, ans);
    count++;
    if(count == k) {
        ans = root->data;
        return;
    }
    solve(root->right, k, count, ans);
}

int kthSmallest(TreeNode<int> *root, int k) {
    int count = 0, ans;
    solve(root, k, count, ans);
    return ans;
}