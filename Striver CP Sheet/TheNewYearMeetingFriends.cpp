// Problem Link: https://codeforces.com/problemset/problem/723/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    cin>> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << (a[1] - a[0]) + (a[2] - a[1]);

    return 0;
}