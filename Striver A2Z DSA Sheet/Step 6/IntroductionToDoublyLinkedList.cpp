/*
Problem Link: https://www.codingninjas.com/studio/problems/introduction-to-doubly-linked-list_8160413?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
 * Definition for doubly-linked list.
 * class Node
 * {
 * public:
 *    int data;
 *    Node *next, *prev;
 *    Node() : data(0), next(nullptr), prev(nullptr) {}
 *    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
 *    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
 * };
 */

Node* constructDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* current = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* node = new Node(arr[i]);
        current->next = node;
        node->prev = current;
        current = node;
    }
    return head;
}