#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<gg, array<gg, 2> > r;
    gg mi, y, res;
    gg p0 = 0, p1 = 0, ans = 0, temp = 0;//p0:����ֵ��result=1��ͬѧ����p1:����ֵ��result=0��ͬѧ��
    cin >> mi;
    for (gg i = 0; i < mi; ++i) {
        cin >> y >> res;
        r[y][res]++;
        if (res == 0)   ++p1;
    }
    for (auto& i : r) {
        gg right = mi - p0 - p1;
        if (right >= temp) {
            temp = right;
            ans = i.first;
        }
        p0 += i.second[1];
        p1 -= i.second[0];
    }
    cout << ans << "\n";
    return 0;
}

//����ؼ���1.ʹ��STL�е�map�������ͳ�� 2.����Ԥ����ȷ���ķ�ʽ�������ظ����㣨��md�ĵ���
    //�����14��r[y][res]++;�ƺ���һ�����������������У������˴�����