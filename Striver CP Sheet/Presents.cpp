// Problem Link: https://codeforces.com/problemset/problem/136/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int giveGift[101], receiveGift[101];
    int n, gift;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> gift;
        giveGift[i] = gift;
        receiveGift[gift] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << receiveGift[i] << " ";
    }

    return 0;
}