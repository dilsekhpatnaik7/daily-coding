/*
Problem Link: https://www.codingninjas.com/studio/problems/more-subsequence_8842355?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(N)
Space Complexity: O(N)
*/

string moreSubsequence(int n, int m, string a, string b) {
    map<char,int> map;
    for(int i = 0;i < n; i++) {
        map[a[i]]++;
    }

    int x = map.size();
    map.erase(map.begin(),map.end());

    for(int i=0;i<m;i++) {
        map[b[i]]++;
    }

    int y = map.size();
    if(x == y)return n >= m ? a : b;

    return x > y ? a : b;
}