// Problem Link: https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1
// GFG I'd: https://auth.geeksforgeeks.org/user/dilsekhpatnaik7

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution{
public:
    bool solve(int n){
        if(n <= 1) return false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i==0) return false;
        }
        return true;
    }
    
    Node *primeList(Node *head){
        Node* temp = head;
        while(temp != NULL){
            int n = temp->val;
            int i = 0;
            while(!solve(n-i) && !solve(n+i)){
                i++;
            }
            if(solve(n-i)) temp->val = (n-i);
            else temp->val = (n+i);

            temp=temp->next;
        }
        return head; 
    }
};