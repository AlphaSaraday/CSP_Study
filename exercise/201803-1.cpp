#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg t, ans, pre;
    cin >> t;
    if(t == 1) ans = pre = 1;
    else ans = pre = 2;
    t = 2;
    cin >> t;
    while(t != 0) {
        if(t == 2) {
            if(pre == 1) {
                ans += 2;
                pre = 2;
            }
            else {
                pre += 2;
                ans += pre;
            }
        }
        else {
            ans += 1;
            pre = 1;
        }
        cin >> t;
    }
    cout << ans << '\n';
    return 0;
}