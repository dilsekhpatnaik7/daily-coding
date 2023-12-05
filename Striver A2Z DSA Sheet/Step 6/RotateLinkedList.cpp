/*
Problem Link: https://www.codingninjas.com/studio/problems/rotate-linked-list_920454?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* getTail(Node* head) {
     while(head->next) {
          head = head->next;
     }
     return head;
}

int getLength(Node* head) {
     int length = 0;
     while(head) {
          length++;
          head = head->next;
     }
     return length;
}

Node* findNNode(Node* head, int n) {
     int count = 1;
     while(head) {
          if(count == n) return head;
          count++;
          head = head->next;
     }
     return head;
}

Node *rotate(Node *head, int k) {
     if(!head || k == 0) return head;

     int length = getLength(head);
     Node* tail = getTail(head);
     if(k % length == 0) return head;
     k = k % length;

     tail->next = head;
     Node* newLastNode = findNNode(head, length - k);
     head = newLastNode->next;
     newLastNode->next = nullptr;

     return head;
}