// Problem Link: https://codeforces.com/problemset/problem/151/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int totalLemons = c * d, totalDrinks = k * l;
    int x = totalDrinks / (n * nl), y = totalLemons / n, z = p / (n * np);
    int ans = min(x, min(y, z));
    cout << ans;

    return 0;
}
