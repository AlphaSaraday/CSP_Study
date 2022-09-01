#include <bits/stdc++.h>
using namespace std;
using gg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, si;
    cin >> ni;
    map<gg, gg> mp;
    while(ni--) {
        cin >> si;
        ++mp[si];
    }
    cout << max_element(mp.begin(), mp.end(), 
                                [](const auto& p1, const auto& p2) {    //这是lambda表达式
                                    return p1.second < p2.second;       //此处的auto其实就是pair<gg, gg>,因为map的内部实现中使用了pair
                                })->first << "\n";                      //为什么是小于号，见https://blog.csdn.net/weixin_43919932/article/details/119830691?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166083113816782350899444%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166083113816782350899444&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-6-119830691-null-null.article_score_rank_blog&utm_term=max_element&spm=1018.2226.3001.4450
    return 0;
}