#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, mi, li, xi;
    cin >> ni >> mi >> li;
    vector<gg> ans(li);//vector就可以将数组的初始长度用变量表示了,注意这里是小括号，中括号则是变长二维数组
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < mi; ++j) {
            cin >> xi;
            ans[xi]++;
        }
    }
    for (gg i : ans) {//C++遍历数组方式
        cout << i << " ";
    }
    return 0;
}