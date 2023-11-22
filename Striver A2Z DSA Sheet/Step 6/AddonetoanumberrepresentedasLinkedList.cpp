/*
Problem Link: https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
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
Node* reverseLinkedList(Node *head) {
    if(!head || !head->next) return head;

    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = current->next;

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

Node *addOne(Node *head) {
    head = reverseLinkedList(head);
    Node* current = head;

    while(current) {
        if (current->next == nullptr && current->data == 9) {
            current->data = 1;
            Node *t = new Node(0);
            t->next = head;
            head = t;
            current = current->next;
        } else if (current->data == 9) {
            current->data = 0;
            current = current->next;
        } else {
            current->data = current->data + 1;
            current = current->next;
            break;
        }
    }
    head = reverseLinkedList(head);
    return head;
}