/*
Problem Link: https://www.geeksforgeeks.org/problems/word-ladder/1

Time Complexity: O(N*word.size()*26)
Space Complexity: O(N)
*/

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        s.erase(startWord);
        
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            
            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        
        return 0;
    }
};