/*
Problem Link: https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* first, Node* second) {
    if(!first) return second;
    if(!second) return first;

    Node* temp = new Node(-1);
    Node* res = temp;
    
    while(first && second) {
        if(first->data <= second->data) {
            temp->child = first;
            temp = first;
            first = first->child;
        } else {
            temp->child = second;
            temp = second;
            second = second->child;
        }
    }
    
    temp->child = first ? first : second;
    return res->child;
}

Node* solve(Node* root) {
    if(!root || !root->next) return root;
    
    Node* root1 = root;
    Node* root2 = solve(root->next);
    root1->next = nullptr;

    return merge(root1, root2);
}

Node* flattenLinkedList(Node* head) {
    if(!head) return head;

	return solve(head);
}