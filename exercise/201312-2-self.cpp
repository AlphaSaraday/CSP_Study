#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    gg count = 1, ans = 0;
    for(gg i =0; i < 12; ++i) {
        if(isdigit(s[i])) {
            ans += stoll(s.substr(i, 1)) * (count++);
            ans %= 11;
        }
    }
    gg judge;
    if(s[12] == 'X')    judge = 10;
    else                judge = stoll(s.substr(12, 1));
    s[12] = (ans == 10) ? 'X' : (ans + 48);
    if(ans == judge)    cout << "Right" << "\n";
    else                cout << s << "\n";
    return 0;
}