// Problem Link: https://codeforces.com/problemset/problem/116/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, count = 0, ans = INT_MIN, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        count -= a;
        count += b;
        ans = max(ans, count);
    }
    cout << ans;

    return 0;
}