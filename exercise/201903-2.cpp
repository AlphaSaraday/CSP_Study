#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    queue<gg> num, op;//这种做法必须用queue，不能用stack，因为把'+'和'-'当做同一优先级【不论左右】了
    gg ni;
    string s;
    cin >> ni;
    while(ni--) {
        cin >> s;
        num.push(s[0] - '0');
        for(gg i = 1; i < s.size(); i += 2) {
            if(s[i] == '+' or s[i] == '-') {
                op.push(s[i]);
                num.push(s[i+1] - '0');
            }
            else {
                if(s[i] == 'x')
                    num.back() *= (s[i+1] - '0');
                else
                    num.back() /= (s[i+1] - '0');
            }
        }
        gg t = num.front(); num.pop();
        while(!op.empty()) {
            char c = op.front(); op.pop();
            t = (c == '+') ? t + num.front() : t - num.front();
            num.pop();
        }
        cout << (t == 24 ? "Yes" : "No") << '\n';
    }
    return 0;
}