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

//������ѭ���������������洢�����롣����ô��������Ϊÿ�δ���������������ƣ�����ֻ��һ��