// Problem Link: https://codeforces.com/problemset/problem/510/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, dir = 0;;
    cin >> n >> m;
    string s1(m, '#'), s2(m, '.');
    for(int r = 0; r < n; r++){
        if(r % 2 == 0) cout << s1 << endl;
        else{
            if(dir == 0) s2[0] = '.', s2[m - 1] = '#';
            else s2[0] = '#', s2[m - 1] = '.';
            cout << s2 << endl;
            dir = 1 - dir;
        }
    }

    return 0;
}