#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, t = 0, d = 0, e = 0;
    cin >> ni;
    vector<bool> drop(ni+1);
    gg count, t1, t2;
    for(gg i = 1; i <= ni; ++i) {
        cin >> count;
        drop[i] = false;
        cin >> t1; t2 = t1; --count;
        while(count--) {
            cin >> t1;
            if(t1 > 0 and t1 < t2) {
                t2 = t1;
                drop[i] = true;
            }
            else if(t1 <= 0) {
                t2 += t1;
            }
        }
        t += t2;
    }
    for(gg i = 1; i <= ni; ++i) {
        if(drop[i] == true) {
            ++d;
            if( (drop[i-1 > 0 ? i-1 : ni] == true)
            and (drop[i+1 > ni ? 1 : i+1] == true) )
                ++e;
        }
    }
    cout << t << ' ' << d << ' ' << e << '\n';
    return 0;
}