#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, mi, ti, tmp;
    gg T = 0;
    pair<gg, gg> ans = {0 ,0};
    cin >> ni >> mi;
    for(gg i = 1; i <= ni; ++i) {
        cin >> ti;
        gg t0 = ti;
        for(gg j = 1; j <=mi; ++j) {
            cin >> tmp;
            ti += tmp;
        }
        if(ans.second < t0 - ti)   ans = {i, t0 - ti};
        T += ti;
    }
    cout << T << ' ' << ans.first << ' ' << ans.second << '\n';
    return 0;
}