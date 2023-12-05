/*
Problem Link: https://www.codingninjas.com/studio/problems/delete-kth-node-from-end_799912?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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

Node* removeKthNode(Node* head, int K) {
    Node* start = new Node();
    start->next = head;
    Node* slow = start;
    Node* fast = start;

    for(int i = 1; i <= K; i++) fast = fast->next;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return start->next;
}