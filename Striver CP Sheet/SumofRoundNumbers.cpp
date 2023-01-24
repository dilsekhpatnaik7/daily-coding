// Problem Link: https://codeforces.com/problemset/problem/1352/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, a[6];
        cin >> n;
        int total = 0, m = 1;
        for(int i = 1; i < 6; i++){
            a[i] = n % 10;
            n /= 10;
            if(a[i] != 0) total++;
        }
        cout << total <<endl;
        for(int i = 1; i < 6; i++){
            if(a[i] != 0) cout << a[i] * m << " ";
            m *= 10;
        }
        cout<<endl;
    }

    return 0;
}