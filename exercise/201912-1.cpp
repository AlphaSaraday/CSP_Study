#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni;
    cin >> ni;
    vector<gg> num;
    gg ans[4] = {0};
    for(gg i = 1; i <= ni; ++i) {
        if(i % 7 == 0 or to_string(i).find('7') != string::npos) {
            num.push_back(i);
            ++ni;
        }
    }
    for(auto& i : num) {
        ++ans[i % 4];
    }
        cout << ans[1] <<'\n';
        cout << ans[2] <<'\n';
        cout << ans[3] <<'\n';
        cout << ans[0] <<'\n';
        return 0;
}