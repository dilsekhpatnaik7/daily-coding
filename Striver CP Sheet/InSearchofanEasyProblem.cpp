// Problem Link: https://codeforces.com/problemset/problem/1030/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        if(m == 1){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";

    return 0;
}