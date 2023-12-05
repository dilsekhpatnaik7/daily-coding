/*
Problem Link: https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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

Node* reverseList(Node* head) {
    if(!head) return nullptr;

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

Node* getKNode(Node* temp, int k) {
    k -= 1;
    while(temp && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = nullptr;
    while(temp) {
        Node* kNode = getKNode(temp, k);
        if(!kNode) {
            if(prevLast) prevLast->next = temp;
            break;
        } 

        Node* nextNode = kNode->next;
        kNode->next = nullptr;
        reverseList(temp);
        if(temp == head) {
            head = kNode;
        } else {
            prevLast->next = kNode;
        }

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}