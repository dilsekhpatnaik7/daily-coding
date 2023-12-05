/*
Problem Link: https://www.codingninjas.com/studio/problems/binary-search-trees_8160443?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N)
Space Complexity: O(1)
*/

bool isValidBST(vector<int> &order){
    for(int i = 1; i < order.size(); i++) {
        if(order[i] <= order[i - 1]) return false;
    }
    return true;
}