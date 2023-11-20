/*
Problem Link: https://www.codingninjas.com/studio/problems/delete-middle-node_763267?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* deleteMiddle(Node* head) {
    if(!head || !head->next) return nullptr;

    Node* slow = head;
    Node* fast = head;
    Node* node = slow;

    while(fast && fast->next) {
        node = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    node->next = slow->next;
    return head;
}