#include <bits/stdc++.h>
#include <array>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni;
    cin >> ni;
    //��Ϊ���ֵ꣬��Ӧ���������������ĸ��ھ�λ�ô��������ĸ������ĸ��Խ�λ
    //�д��������ĸ���
    map< array<gg, 2>, array<gg, 2> > mi;
    array<gg, 2> p0;
    while(ni--) {
        cin >> p0[0] >> p0[1];
        mi.insert({p0, {0, 0}}); //����ǰ��������ϣ���У�Ĭ���ھ�λ�úͶԽ�λ������������Ϊ0
        for(auto& i : mi) {
            array<gg, 2> p1 = i.first;
            if( (abs(p0[0] - p1[0]) == 1 and p0[1] == p1[1]) or
                (abs(p0[1] - p1[1]) == 1 and p0[0] == p1[0]) )//�ھ�λ�ô�������
            {
                ++mi[p0][0];
                ++mi[p1][0];
            }
            else if(abs(p0[0] - p1[0]) == 1 and abs(p0[1] - p1[1]) == 1)//�Խ�λ�ô�������
            {
                ++mi[p0][1];
                ++mi[p1][1];
            }
        }
    }
    array<gg, 5> ans = {0};
    for(auto& i : mi) {
        if(i.second[0] == 4) {
            ++ans[i.second[1]];
        }
    }
    for(auto& i :ans) {
        cout << i << '\n';
    }
    return 0;
}