#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e7 + 2e6;
string t, s;
int n, m;
int l[N];

int main () {
    cin >> t;
    m = t.length();
    n = (m << 1) + 1;
    s.resize(n + 1);
    //其中s[0]='@',s[n]='%',中间插入的字符为'#'
    s[0] = '@', s[n] = '%', s[1] = '#';
    for (int i = 1; i <= m; i ++) {
        s[i << 1] = t[i - 1];
        s[i << 1 | 1] = '#';
    }
    //Manacher algorithm
    int ans = 0, k = 0, r = 0;
    l[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (i < r) l[i] = min (r - i, l[(k << 1) - i]);
        else l[i] = 1;

        while (s[i - l[i]] == s[i + l[i]]) l[i] ++; // 暴力更新超过r的部分
        if (i + l[i] > r) k = i, r = i + l[i]; // 更新k,r
        ans = max (ans, l[i] - 1); // 找到最长回文子串
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}

//https://blog.csdn.net/weixin_43501684/article/details/124325764