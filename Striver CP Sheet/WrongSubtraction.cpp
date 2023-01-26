// Problem Link: https://codeforces.com/problemset/problem/977/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    while(k--){
        if(n % 10) n--;
        else n /= 10;
    }
    cout << n;

    return 0;
}