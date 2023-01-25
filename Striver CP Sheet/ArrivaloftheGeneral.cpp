// Problem Link: https://codeforces.com/problemset/problem/144/A?csrf_token=1f1c5990122e49d93478a8931d050c19

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, lh = INT_MIN, li = 0, rh = INT_MAX, ri = 0, h;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h;
        if(h > lh) lh = h, li = i;
        if(h <= rh) rh = h, ri = i;
    }
    int res = li + n - 1 - ri;
    if(li < ri) cout << res;
    else cout << res - 1;

    return 0;
}