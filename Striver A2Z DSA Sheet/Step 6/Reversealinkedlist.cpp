/*
Problem Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

struct Node* reverseList(struct Node *head) {
    if(!head) return head;

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = current->next;

    while(current) {
        current->next = prev;
        prev = current;
        current = nextNode;
        if(nextNode) {
            nextNode = nextNode->next;
        }
    }
    return prev;   
}