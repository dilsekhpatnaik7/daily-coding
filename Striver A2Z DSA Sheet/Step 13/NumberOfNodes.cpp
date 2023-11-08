/*
Problem Link: https://www.codingninjas.com/studio/problems/number-of-nodes_8162204?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

int numberOfNodes(int N) {
    if(N <= 2) return N;
    return pow(2, N - 1);
}