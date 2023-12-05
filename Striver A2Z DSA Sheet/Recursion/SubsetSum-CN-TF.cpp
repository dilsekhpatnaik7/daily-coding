/*
Problem Link: https://www.codingninjas.com/studio/problems/subset-sum_630213?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N)
*/

bool subsetSum(int index, int sum, int k, vector<int>& a) {
    if(index == a.size()) {
        if(sum == k) return true;
        else return false;
    }

    if(sum <= k) {
        sum += a[index];
        if(subsetSum(index + 1, sum, k, a)) return true;
        sum -= a[index];
    }
    if(subsetSum(index + 1, sum, k, a)) return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    return subsetSum(0, 0, k, a);
}