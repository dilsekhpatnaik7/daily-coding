/*
Problem Link: https://www.codingninjas.com/studio/problems/print-nodes-at-distance-k-from-a-given-node_842560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
	public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void markParents(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& m) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if(node->left) {
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            m[node->right] = node;
            q.push(node->right);
        }
    }
}

void solve(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& m, BinaryTreeNode<int>* target, int k, vector<BinaryTreeNode<int>*>& ans) {
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    visited[target] = true;
    int currentLevel = 0;

    while(!q.empty()) {
        int size = q.size();
        if(currentLevel++ == k) break;

        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(m[node] && !visited[m[node]]) {
                q.push(m[node]);
                visited[m[node]] = true;
            }
        }
    }

    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); q.pop();
        ans.push_back(node);
    }
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    if(!root) return {};
     
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> m;
    markParents(root, m);

    vector<BinaryTreeNode<int>*> ans;
    solve(root, m, target, K, ans);
    return ans;
}