/*
Problem Link: https://www.codingninjas.com/studio/problems/word-ladder_1102319?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

Time Complexity: O(N*word.size()*26)
Space Complexity: O(N)
*/

#include<bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict) {
	unordered_set<string> s(dict.begin(), dict.end());
	queue<pair<string, int>> q;
	q.push({begin, 1});
	s.erase(begin);
	
	while(!q.empty()) {
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();
		if(word == end) return steps;
		
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
	
	return -1;
}