/*
Problem Link: https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        struct Node* temp = *head;
        while(temp) {
            if(temp->data == x) {
                if(temp == *head) {
                    *head = temp->next;
                    if(*head) (*head)->prev = NULL;
                    struct Node* nextNode = temp->next;
                    free(temp);
                    temp = nextNode;
                } else {
                    struct Node* prevNode = temp->prev;
                    struct Node* nextNode = temp->next;

                    if(prevNode) prevNode->next = nextNode;
                    if(nextNode) nextNode->prev = prevNode;

                    free(temp);
                    temp = nextNode;
                }
            } else {
                temp = temp->next;
            }
        }
    }
};