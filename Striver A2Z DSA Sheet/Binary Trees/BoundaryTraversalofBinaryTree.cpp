/*
Problem Link: https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root) {
    return root && (!root->left && !root->right);
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* node = root->left;
    
    while(node) {
        if(!isLeaf(node)) ans.push_back(node->data);
        if(node->left) node = node->left;
        else if(node->right) node = node->right;
        else break;
    }
}

void addRightBoundary(TreeNode<int>* root, vector<int>& ans) {
    TreeNode<int>* node = root->right;
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

void addLeaf(TreeNode<int>* root, vector<int>& ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left, ans);
    if(root->right) addLeaf(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root) {
    if(!root) return {};
        
    vector<int> ans; 
    if(!isLeaf(root)) ans.push_back(root->data);
    
    addLeftBoundary(root, ans);
    addLeaf(root, ans);
    addRightBoundary(root, ans);
    
    return ans;
}