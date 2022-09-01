#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, score, weight;
    gg ans = 0;
    cin >> ni;
    while(ni > 0) {
        cin >> weight >> score;
        ans += weight * score;
        --ni;
    }
    cout << max(0ll, ans);
    return 0;
}

//本题用循环输入代替了数组存储再输入。能这么处理是因为每次处理的数据作用相似，并且只用一次