/*
Problem Link: https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
long long solve(Node* slow, Node* node) {
    long long count = 1;
    while(slow != node) {
        node = node->next;
        count++;
    }
    return count;
}

int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return (int)solve(slow, slow->next);
        }
    }
    return 0;
}