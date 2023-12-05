/*
Problem Link: https://www.codingninjas.com/studio/problems/add-two-numbers_1170520?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2) {
    Node* dummy = new Node(-1);
    Node* head = dummy;
    int carry = 0;
    while(num1 || num2 || carry) {
        int sum = 0;
        if(num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if(num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node* node = new Node(sum % 10);
        head->next = node;
        head = head->next;
    }
    return head = dummy->next;
}