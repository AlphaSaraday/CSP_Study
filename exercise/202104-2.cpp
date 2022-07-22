#include <bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg MAX = 6e2 + 5;
gg ni, li, ri, ti;
gg a[MAX][MAX], preSum[MAX][MAX];//����ȫ�ֱ���������Ĭ�ϳ�ʼ��Ϊ0
//����ǰ׺��
void getPrefixSum(gg m, gg n) {
    for (gg i = 1; i <= m; ++i) {
        for (gg j = 1; j <= n; ++j) {
            preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + a[i][j];
        }
    }
}
//���㽫���Ͻ�Ϊ(r1,c1)�����½�Ϊ(r2,c2)�ľ���ĺ�
gg getSum(gg r1, gg c1, gg r2, gg c2) {
    return preSum[r2][c2] - preSum[r1 - 1][c2] - preSum[r2][c1 - 1] + preSum[r1 - 1][c1 - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ni >> li >> ri >> ti;
    for (gg i = 1; i <= ni; ++i) {
        for (gg j = 1; j <= ni; ++j) {
            cin >> a[i][j];
        }
    }
    getPrefixSum(ni, ni);
    gg ans = 0;
    for (gg i = 1; i <= ni; ++i) {
        for (gg j = 1; j <= ni; ++j) {
            gg a = max(1ll, i - ri), b = max(1ll, j - ri), c = min(ni, i + ri), d = min(ni, j + ri);//1ll:ǿ�Ƴ���1Ϊgg���ͣ���ֹ�Ƚϴ�С��ʱ�򷭳�
            gg res = getSum(a, b, c, d);
            if (res <= ti * (c - a + 1) * (d - b + 1)) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

//����ؼ���1.�����������״����ʾ��2.�ö�άǰ׺�ͽ���ʱ�临�Ӷ�