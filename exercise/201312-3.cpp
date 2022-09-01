#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, ans = 0;
    cin >> ni;
    vector<gg> h(ni);
    for(auto& i : h) {
        cin >> i;
    }
    for(gg i = 0; i < ni; ++i) {
        gg length = h[i], j , k;
        for(j = i+1; j < ni; ++j) {
            if(length > h[j]) break;
        }
        for(k = i-1; k >= 0; --k) {
            if(length > h[k]) break;
        }
        gg width = j - k - 1;
        ans = max(ans, length * width);
    }
    cout << ans << "\n";
    return 0;
}