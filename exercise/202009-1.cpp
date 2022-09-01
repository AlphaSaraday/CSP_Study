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

//本题关键：1.利用set内部红黑树自动排序 2.注意ans.end()迭代器是指向最后一个元素的下一个位置，所以要用prev函数
//http://c.biancheng.net/view/7384.html