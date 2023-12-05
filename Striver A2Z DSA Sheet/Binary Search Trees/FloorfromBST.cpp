/*
Problem Link: https://www.codingninjas.com/studio/problems/floor-from-bst_625868?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(log(N))
Space Complexity: O(1)
*/

int Floor(BinaryTreeNode<int> *node, int input) {
	int f = -1;
	while(node) {
		if(node->data == input) return input;
		if(input > node->data) {
			f = node->data;
			node = node->right;
		} else node = node->left;
	}
	return f;
}
