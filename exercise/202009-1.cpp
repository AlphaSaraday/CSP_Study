#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, xi, yi, a, b;
    set<array<gg, 2>> ans;
    cin >> ni >> xi >> yi;
    for(gg i =1; i <= ni; i++) {
        cin >> a >> b;
        gg d = (xi-a)*(xi-a) + (yi-b)*(yi-b);
        if(ans.size() >= 3) {
            if((*ans.rbegin())[0] > d) {
                ans.erase(prev(ans.end()));
                ans.insert({d, i});
            }
        }
        else {
            ans.insert({d, i});
        }
    }
    for(auto& i : ans){
        cout << i[1] << "\n";
    }
    return 0;
}

//����ؼ���1.����set�ڲ�������Զ����� 2.ע��ans.end()��������ָ�����һ��Ԫ�ص���һ��λ�ã�����Ҫ��prev����
//http://c.biancheng.net/view/7384.html