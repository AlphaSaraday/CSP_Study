#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll ni, mi, li, xi;
    cin >> ni >> mi >> li;
    vector<ll> ans(li);//vector就可以将数组的初始长度用变量表示了,注意这里是小括号，中括号则是变长二维数组
    for (ll i = 0; i < ni; ++i) {
        for (ll j = 0; j < mi; ++j) {
            cin >> xi;
            ans[xi]++;
        }
    }
    for (ll i : ans) {//C++遍历数组方式
        cout << i << " ";
    }
    return 0;
}