#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll ni, mi, li, xi;
    cin >> ni >> mi >> li;
    vector<ll> ans(li);//vector�Ϳ��Խ�����ĳ�ʼ�����ñ�����ʾ��,ע��������С���ţ����������Ǳ䳤��ά����
    for (ll i = 0; i < ni; ++i) {
        for (ll j = 0; j < mi; ++j) {
            cin >> xi;
            ans[xi]++;
        }
    }
    for (ll i : ans) {//C++�������鷽ʽ
        cout << i << " ";
    }
    return 0;
}