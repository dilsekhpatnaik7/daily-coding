/*
Problem Link: https://www.codingninjas.com/studio/problems/zigzag-binary-tree-traversal_920532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
void solve(TreeNode<int>* &root, vector<int>& ans) {
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0 ; i < size; i++) {
            TreeNode<int>* node = q.front();
            q.pop();

            if(node) {
                ans.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
}

vector<int> levelOrder(TreeNode<int> * root){
    if(!root) return {};

    vector<int> ans;
    solve(root, ans);
    return ans;
}
