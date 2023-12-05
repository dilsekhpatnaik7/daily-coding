/*
Problem Link: https://www.codingninjas.com/studio/problems/reverse-linked-list_920513?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

/****************************************************************

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
        

*****************************************************************/

Node* reverseLinkedList(Node *head) {
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