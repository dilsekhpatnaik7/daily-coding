/*
Problem Link: https://www.codingninjas.com/studio/problems/serialize-and-deserialize-binary-tree_920328?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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

string serializeTree(TreeNode<int> *root) {
    if(!root) return "";

    string s = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* node = q.front(); q.pop();
        if(!node) s += "-1 ";
        else s.append(to_string(node->data) + ' ');

        if(node) {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized) {
    if(serialized.size() == 0) return nullptr;

    stringstream s(serialized);
    string str;
    getline(s, str, ' ');
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int>* node = q.front(); q.pop();

        getline(s, str, ' ');
        if(str == "-1") {
            node->left = NULL;
        } else {
            TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ' ');
        if(str == "-1") {
            node->right = NULL;
        } else {
            TreeNode<int>* rightNode = new TreeNode<int>(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}