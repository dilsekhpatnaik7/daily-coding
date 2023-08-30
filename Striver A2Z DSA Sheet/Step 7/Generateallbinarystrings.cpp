/*
Problem Link: https://practice.geeksforgeeks.org/problems/generate-all-binary-strings/1

Time Complexity: O(2 ^ N)
Space Complexity: O(2 ^ N + N)
*/

class Solution{
public:
    void generateAllBinaryStrings(int index, int num, string str) {
        if(index == num) {
            cout << str << " ";
            return;
        }
        generateAllBinaryStrings(index + 1, num, str + '0');
        
        
        if(index == 0 || (index > 0 && str[index - 1] != '1')) {
            generateAllBinaryStrings(index + 1, num, str + '1');
        }
    }
    
    void generateBinaryStrings(int num){
        string str = "";
        generateAllBinaryStrings(0, num, str);
    }
};