/*
Problem Link: https://www.codingninjas.com/studio/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* segregateEvenOdd(Node* head) {
    if(!head) return head;
        
    Node* node = head;
    Node* evenList = NULL;
    Node* oddList = NULL;
    Node* even = NULL;
    Node* odd = NULL;
    
    while(node) {
        if(node->data % 2 == 0) {
            if(!evenList) {
                evenList = node;
                even = node;
            } else {
                evenList->next = node;
                evenList = evenList->next;
            }
        } else {
            if(!oddList) {
                oddList = node;
                odd = node;
            } else {
                oddList->next = node;
                oddList = oddList->next;
            }
        }
        node = node->next;
    }
    
    if(evenList) evenList->next = odd;
    if(oddList) oddList->next = NULL;
    
    if(even) return even;
    return odd;
}