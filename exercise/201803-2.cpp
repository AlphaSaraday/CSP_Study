#include <bits/stdc++.h>
using namespace std;
using gg =long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, li, ti;
    cin >> ni >> li >> ti;
    gg position[1005][3];//位置上小球的个数
    pair<gg, gg> ball[105]; //ni个小球的位置和速度
    gg place;
    for(int i = 0; i < ni; ++i) {
        cin >> place;
        ball[i].first = place;
        ball[i].second = 1;
    }
    while(ti--) {
        memset(position, 0 , sizeof(position));
        for(int i = 0; i < ni; ++i) {
            ball[i].first += ball[i].second;
            if(ball[i].first == li)   ball[i].second = -1;
            if(ball[i].first ==  0)   ball[i].second = 1;
            ++position[ball[i].first][0];
            position[ball[i].first][position[ball[i].first][0]] = i;
        }
        for(int i = 0; i < li; ++i) {
            if(position[i][0] > 1) {
                if(ball[position[i][1]].second == 1)
                    ball[position[i][1]].second = -1;
                else ball[position[i][1]].second = 1;
                if(ball[position[i][2]].second == 1)
                    ball[position[i][2]].second = -1;
                else ball[position[i][2]].second = 1;
            }
        }   
    }
    for(int i = 0; i < ni; ++i) {
        cout << ball[i].first << ' ';
    }
    return 0;
}