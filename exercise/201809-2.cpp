#include <bits/stdc++.h>
using namespace std;
using gg = long long;

//����ʱ�����������غϵķ���
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, ans = 0;
    gg a[1000005] = {0}, b[1000005] = {0};
    gg s, t;
    cin >> ni;
    for(gg i = 0; i < ni; i++) {
        cin >> s >> t;
        while(s != t) a[s++] = 1;
    }
    for(gg i = 0; i < ni; i++) {
        cin >> s >> t;
        while(s != t) b[s++] = 1;
    }
    for(gg i = 1; i < t; ++i) {
        if((a[i] == 1) and (b[i] == 1))
            ++ans;
    }
    cout << ans << '\n';
    return 0;
}
//����ö�ٵķ���Ҳͦ���,�������ÿռ����
/*
    int ni, ans = 0;
    cin >> ni;
    vector<array<gg, 2>> v1(ni), v2(ni);  //�ֱ�洢СH��СW��װ��ʱ���
    for (int i = 0; i < ni; ++i) {
        cin >> v1[i][0] >> v1[i][1];
    }
    for (int i = 0; i < ni; ++i) {
        cin >> v2[i][0] >> v2[i][1];
    }
    for (auto& p1 : v1) {
        for (auto& p2 : v2) {
            if (p1[0] <= p2[1] and p1[1] >= p2[0]) {  //�ж������ص�����
                ans += min(p1[1], p2[1]) - max(p1[0], p2[0]);
            }
        }
    }
    cout << ans;
*/