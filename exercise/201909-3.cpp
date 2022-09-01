#include <bits/stdc++.h>
#include <array>
using namespace std;
using gg = long long;
using ag = array<gg, 3>;
void output(string& s, ag rgb = {0, 0, 0}) {  //���
    for (char c : s)
        if (c == 'R' or c == 'G' or c == 'B') {  //��RGB��ֵ
            string t = to_string(rgb[c == 'R' ? 0 : c == 'G' ? 1 : 2]);  //����ֵת�����ַ���
            for (gg cc : t)  //�����ַ���
                cout << "\\x" << setw(2) << cc;  //���16������
        } else
            cout << "\\x" << setw(2) << gg(c);  //���16������
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string back = "\x1b[48;2;R;G;Bm", reset = "\x1b[0m";  //����ɫ������Ĭ��ֵ�ַ���
    gg m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<ag>> image(n);  //ͼ������
    string rgb;
    for (gg i = 0; i < n; ++i) {
        for (gg j = 0; j < m; ++j) {
            cin >> rgb;
            if (rgb.size() == 2)  //ֻ��2λ�ַ�
                rgb += string(5, rgb.back());  //�ַ���ĩβ���5��ĩβ�ַ�
            else if (rgb.size() == 4)  //ֻ��4λ�ַ�
                rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);  //��ӳ�Ϊ6λ
            image[i].push_back({0, 0, 0});
            for (gg t = 0; t < 3; ++t)  //����RGB��ֵ����16������ת����10����
                image[i].back()[t] = stoll(rgb.substr(2 * t + 1, 2), 0, 16);
        }
    }
    cout << hex << uppercase << setfill('0');
    ag last = {0, 0, 0}, start = {0, 0, 0};
    for (gg i = 0; i < n / q; ++i) {  //������������
        for (gg j = 0; j < m / p; ++j) {
            ag cur = {0, 0, 0};
            for (gg r = 0; r < q; ++r) {  //�������RGB��ɫ����֮��
                for (gg s = 0; s < p; ++s) {
                    for (gg t = 0; t < 3; ++t)
                        cur[t] += image[i * q + r][j * p + s][t];
                }
            }
            for (gg t = 0; t < 3; ++t)  //����RGB��ɫ����ƽ��ֵ
                cur[t] /= p * q;
            if (cur != last)  //����һ������ɫ������ͬ
                if (cur == start)  //��Ĭ����ɫ����һ�£��������ת������
                    output(reset);
                else
                    output(back, cur);
            last = cur;  //������һ��״̬Ϊ��ǰ״̬
            cout << "\\x" << setw(2) << gg(' ');  //ÿһ��������һ���ո�
        }
        if (last != start)  //ÿһ�н�����ָ�Ĭ��״̬
            output(reset);
        last = start;  //ÿһ�н����������һ��״̬λĬ��״̬
        cout << "\\x" << setw(2) << gg('\n');  //ÿһ���ַ������һ������
    }
    return 0;
}