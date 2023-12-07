/*
Problem Link: https://www.codingninjas.com/studio/problems/counting-graphs_8357237?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(1)
Space Complexity: O(1)
*/

int countingGraphs(int N) {
    return pow(2, N*(N-1) / 2);
}