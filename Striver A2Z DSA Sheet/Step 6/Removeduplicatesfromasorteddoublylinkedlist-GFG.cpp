/*
Problem Link: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    Node* removeDuplicates(struct Node *head) {
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
};