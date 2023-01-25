// Problem Link: https://codeforces.com/problemset/problem/110/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    int c = 0;
    cin >> s;
    for(auto i: s) {
        if(i == '4' || i == '7') c++;
    }
    if(c == 4 || c == 7) cout << "YES";
    else cout << "NO";

    return 0;
}