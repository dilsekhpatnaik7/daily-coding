/*
Problem Link: https://www.codingninjas.com/studio/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
Node* findTail(Node* head) {
    Node* temp = head;
    while(temp->next) temp = temp->next;
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k) {
    if(!head) return {};

    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data) {
        if(left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < k) {
            left = left->next;
        } else right = right->prev;
    }
    return ans;
}