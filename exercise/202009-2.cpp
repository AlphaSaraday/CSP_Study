#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ans1 = 0, ans2 = 0;//经过和逗留
    gg ni, ki, ti, x1, y1, x2, y2, a, b;
    cin >> ni >> ki >> ti >> x1 >>y1 >> x2 >> y2;
    while(ni--) {
        gg temp = 0;
        bool f1 = false, f2 = false;
        for(gg i = 1; i <= ti; i++) {
           cin >> a >> b;
           if(a>=x1 and a<=x2 and b>=y1 and b<=y2) {
               f1 = true; temp++;
               if(temp >= ki)   f2 = true;
           }
           else temp = 0;
        }
        if(f1)  ans1++;
        if(f2)  ans2++;
    }
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}

//本题关键：注意看清题目，逗留为“连续”