// Problem Link: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for (int i = 0; i < order.length(); i++) {
            map[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            string first = words[i - 1];
            string second = words[i];
            int n = min(first.length(), second.length());
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (map[first[j]] < map[second[j]]) {
                    flag = true;
                    break;
                }
                else if (map[first[j]] > map[second[j]]) {
                    return false;
                }
            }
            if (!flag && first.length() > second.length()) {
                return false;
            }
        }
        return true;
    }
};