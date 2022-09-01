#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, MAX, MIN;
    cin >> ni;
    vector<gg> v(ni);
    for(auto& i : v) {
        cin >> i;
    }
    MAX = max(v[0], v[ni-1]);
    MIN = min(v[0], v[ni-1]);
    gg mid1, mid2;
    if(ni % 2 == 1) mid1 = mid2 = v[(ni+1)/2 -1];
    else mid1 = v[ni/2 -1], mid2 = v[ni/2];
    cout << MAX << ' ' << fixed << setprecision((mid1 + mid2) % 2 == 0 ? 0 : 1)
         << (mid1 + mid2)/2.0 << ' ' << MIN << '\n';
    return 0;
}