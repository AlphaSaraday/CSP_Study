#include <bits/stdc++.h>
using namespace std;
using gg = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, mi, li, xi;
    cin >> ni >> mi >> li;
    vector<gg> ans(li);//vector�Ϳ��Խ�����ĳ�ʼ�����ñ�����ʾ��,ע��������С���ţ����������Ǳ䳤��ά����
    for (gg i = 0; i < ni; ++i) {
        for (gg j = 0; j < mi; ++j) {
            cin >> xi;
            ans[xi]++;
        }
    }
    for (gg i : ans) {//C++�������鷽ʽ
        cout << i << " ";
    }
    return 0;
}