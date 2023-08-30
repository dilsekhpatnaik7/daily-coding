/*
Problem Link: https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

void generateAllBinaryStrings(int index, int N, string str, vector<string>& ans) {
    if(index == N) {
        ans.push_back(str);
        return;
    }

    generateAllBinaryStrings(index + 1, N, str + '0', ans);
    if(index == 0 || (index > 0 && str[index - 1] != '1')) {
        generateAllBinaryStrings(index + 1, N, str + '1', ans);
    }
}

vector<string> generateString(int N) {
    vector<string> ans;
    generateAllBinaryStrings(0, N, "", ans);
    return ans;
}