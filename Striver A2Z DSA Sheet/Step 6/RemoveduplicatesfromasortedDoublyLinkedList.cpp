/*
Problem Link: https://www.codingninjas.com/studio/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
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
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node* removeDuplicates(Node *head) {
    Node* node = head;
    while(node && node->next) {
        Node* nextNode = node->next;
        while(nextNode && nextNode->data == node->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        node->next = nextNode;
        if(nextNode) nextNode->prev = node;

        node = node->next;
    }
    return head;
}