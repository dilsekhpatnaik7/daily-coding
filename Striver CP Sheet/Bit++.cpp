// Problem Link: https://codeforces.com/problemset/problem/282/A?csrf_token=1f1c5990122e49d93478a8931d050c19

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ans = 0;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s == "++X" || s == "X++") ans++;
        if(s == "--X" || s == "X--") ans--;
    }
    cout << ans;

    return 0;
}