#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<gg, array<gg, 2> > r;
    gg mi, y, res;
    gg p0 = 0, p1 = 0, ans = 0, temp = 0;//p0:＜阈值且result=1的同学数；p1:≥阈值且result=0的同学数
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

//本题关键：1.使用STL中的map来排序和统计 2.计算预测正确数的方式，避免重复计算（见md文档）
    //代码第14行r[y][res]++;似乎有一个错误但是能正常运行，暂留此处待解