#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    gg count = 1, ans = 0, length = s.size()-1;
    for(gg i = 0; i < length; ++i) {
        if(isdigit(s[i])) {
            ans += (s[i] - '0') * (count++);
            ans %= 11;
        }
    }
    char judge = (ans == 10) ? 'X' : ans + '0';
    if(s.back() == judge) {
        cout << "Right" << "\n";
    }
    else {
        s.back() = judge;
        cout << s << "\n";
    }
    return 0;
}