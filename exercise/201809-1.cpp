#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni;
    gg first[1005], second[1005];
    cin >> ni;
    for(gg i = 0; i < ni; ++i) {
        cin >> first[i];
    }
    gg tmp1 = (first[0] + first[1]) / 2;
    gg tmp2 = (first[ni-2] + first[ni-1]) / 2;
    for(gg i = 1; i < ni-1; ++i) {
        second[i] = (first[i-1] + first[i] + first[i+1]) / 3;
    }
    second[0] = tmp1;  second[ni-1] = tmp2;
    for(gg i = 0; i < ni; ++i) {
        cout << second[i] << ' ';
    }
    cout << '\n';
    return 0;
}