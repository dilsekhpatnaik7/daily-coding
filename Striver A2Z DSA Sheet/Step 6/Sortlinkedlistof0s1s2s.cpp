/*
Problem Link: https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

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

Node* sortList(Node *head) {
    int count[3] = {0};
    Node* node = head;
    while(node) {
        count[node->data]++;

        node = node->next;
    }
    
    node = head;
    int index = 0;
    while(node) {
        if(count[index] == 0) index++;
        if(count[index] != 0) {
            node->data = index;
            count[index]--;
            node = node->next;
        }
    }
    return head;
}