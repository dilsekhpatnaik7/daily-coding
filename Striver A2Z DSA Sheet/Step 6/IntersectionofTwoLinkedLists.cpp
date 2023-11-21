/*
Problem Link: https://www.codingninjas.com/studio/problems/-intersection-of-two-linked-lists_630457?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(N)
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

Node* findIntersection(Node *firstHead, Node *secondHead) {
    if(!firstHead || !secondHead) return nullptr;

    Node* a = firstHead;
    Node* b = secondHead;
    while(a != b) {
        a = a == NULL ? secondHead : a->next;
        b = b == NULL ? firstHead : b->next;
    }
    return a;
}