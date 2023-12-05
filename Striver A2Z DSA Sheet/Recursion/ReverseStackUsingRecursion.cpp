/*
Problem Link: https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N ^ 2)
Space Cmplexity: O(N)
*/

void insertAtPosition(int x, stack<int>& stack) {
    if(stack.size() == 0) stack.push(x);
    else {
        int a = stack.top();
        stack.pop();
        insertAtPosition(x, stack);
        stack.push(a);
    }
}

void reverse(stack<int>& stack) {
    if(stack.size() > 0) {
        int x = stack.top();
        stack.pop();
        reverse(stack);
        insertAtPosition(x, stack);
    }
}

void reverseStack(stack<int> &stack) {
    reverse(stack);
}