#include <bits/stdc++.h>
#include <array>
using namespace std;
using gg = long long;
using ag = array<gg, 3>;
void output(string& s, ag rgb = {0, 0, 0}) {  //输出
    for (char c : s)
        if (c == 'R' or c == 'G' or c == 'B') {  //是RGB数值
            string t = to_string(rgb[c == 'R' ? 0 : c == 'G' ? 1 : 2]);  //将数值转换成字符串
            for (gg cc : t)  //遍历字符串
                cout << "\\x" << setw(2) << cc;  //输出16进制数
        } else
            cout << "\\x" << setw(2) << gg(c);  //输出16进制数
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string back = "\x1b[48;2;R;G;Bm", reset = "\x1b[0m";  //背景色和重置默认值字符串
    gg m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<ag>> image(n);  //图像像素
    string rgb;
    for (gg i = 0; i < n; ++i) {
        for (gg j = 0; j < m; ++j) {
            cin >> rgb;
            if (rgb.size() == 2)  //只有2位字符
                rgb += string(5, rgb.back());  //字符串末尾添加5个末尾字符
            else if (rgb.size() == 4)  //只有4位字符
                rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);  //添加成为6位
            image[i].push_back({0, 0, 0});
            for (gg t = 0; t < 3; ++t)  //计算RGB数值，将16进制数转换成10进制
                image[i].back()[t] = stoll(rgb.substr(2 * t + 1, 2), 0, 16);
        }
    }
    cout << hex << uppercase << setfill('0');
    ag last = {0, 0, 0}, start = {0, 0, 0};
    for (gg i = 0; i < n / q; ++i) {  //遍历所有像素
        for (gg j = 0; j < m / p; ++j) {
            ag cur = {0, 0, 0};
            for (gg r = 0; r < q; ++r) {  //计算块内RGB颜色分量之和
                for (gg s = 0; s < p; ++s) {
                    for (gg t = 0; t < 3; ++t)
                        cur[t] += image[i * q + r][j * p + s][t];
                }
            }
            for (gg t = 0; t < 3; ++t)  //计算RGB颜色分量平均值
                cur[t] /= p * q;
            if (cur != last)  //和上一个块颜色分量不同
                if (cur == start)  //和默认颜色分量一致，输出重置转义序列
                    output(reset);
                else
                    output(back, cur);
            last = cur;  //更新上一个状态为当前状态
            cout << "\\x" << setw(2) << gg(' ');  //每一个块后输出一个空格
        }
        if (last != start)  //每一行结束后恢复默认状态
            output(reset);
        last = start;  //每一行结束后更新上一个状态位默认状态
        cout << "\\x" << setw(2) << gg('\n');  //每一行字符后输出一个换行
    }
    return 0;
}