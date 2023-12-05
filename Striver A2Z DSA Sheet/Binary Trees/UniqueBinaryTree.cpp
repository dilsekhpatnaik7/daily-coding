/*
Problem Link: https://www.codingninjas.com/studio/problems/unique-binary-tree_8180906?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

int uniqueBinaryTree(int a, int b){
    if(((a == 1 || a == 3) && b == 2) || (a == 2 &&(b == 1 || b == 3))) return 1;
    return 0;
}