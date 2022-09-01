#include <bits/stdc++.h>
#include <array>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni;
    cin >> ni;
    //键为坐标，值对应该坐标上下左右四个邻居位置存在垃圾的个数和四个对角位
    //中存在垃圾的个数
    map< array<gg, 2>, array<gg, 2> > mi;
    array<gg, 2> p0;
    while(ni--) {
        cin >> p0[0] >> p0[1];
        mi.insert({p0, {0, 0}}); //将当前坐标插入哈希表中，默认邻居位置和对角位置垃圾个数均为0
        for(auto& i : mi) {
            array<gg, 2> p1 = i.first;
            if( (abs(p0[0] - p1[0]) == 1 and p0[1] == p1[1]) or
                (abs(p0[1] - p1[1]) == 1 and p0[0] == p1[0]) )//邻居位置存在垃圾
            {
                ++mi[p0][0];
                ++mi[p1][0];
            }
            else if(abs(p0[0] - p1[0]) == 1 and abs(p0[1] - p1[1]) == 1)//对角位置存在垃圾
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