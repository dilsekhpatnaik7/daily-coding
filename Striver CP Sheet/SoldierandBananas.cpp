// Problem Link: https://codeforces.com/problemset/problem/546/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k, n, w, ans = 0;
    cin >> k >> n >> w;
    for(int i = 1; i <= w; i++){
        ans += i * k;
    }
    if(ans - n < 0) cout << "0";
    else cout << ans - n; 

    return 0;
}