#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string equation;
unordered_map<string, gg> ans;

//ע��������ã�����������ʱfirst�Ѿ�ָ�����ֺ�(�����ֵĻ�)�ĵ�һ��Ԫ����ĸ
gg digits(gg& first, gg last) {
    gg e = 0;
    for(; first <= last and isdigit(equation[first]); ++first) {
        e = 10 * e + equation[first] - '0';
    }
    return (e > 0) ? e : 1;
}

//����formula��[first,last]�����ԭ�Ӽ����Ӧϵ��������ϵ��Ϊe
void handle(gg first, gg last, gg e) {
    //�ݹ��յ㣺����ԭ��
    if((first == last) or (first + 1 == last and islower(equation[last]))) {
        ans[equation.substr(first, last - first + 1)] += e;
        return;//�ǵ�return
    }
    //��ʼ����ֽ⵱ǰʽ��
    e *= digits(first, last);//��ǰʽ��������ԭ�ӻ���ϵ��Ҫ���ϵ�ǰʽ����ʼϵ��
    for(gg i = first, j = i+1; i <= last; i = j, ++j) {
        if(isupper(equation[i])) { //�����ţ�һ��һ��Ԫ��/ԭ�Ӵ���
            if(j <= last and islower(equation[j])) {
                ++j;
            }
            gg k = j;//�������Ҫ������Ҫ��j��ֵ����������Ȼ����һ��handleִ��֮ǰ����ִ����digits�����j��ֵ��
            handle(i, k-1, e*digits(j, last));//�Ѿ��ݹ鵽�յ㣬digits(j, last)�Ǽ��㱶������Cl2��2
        }
        else if(equation[i] == '(') { //�����ţ������ڵ����ж��������µĵ�ǰʽ�ݹ鴦��
            gg num = 1;
            while(num != 0){
                if(equation[j] == '(')          ++num;
                else if(equation[j] == ')')     --num;
                ++j;
            }
            gg k = j;
            handle(i+1, k-1, e*digits(j, last));//digits(j, last)�Ǽ��㱶������(PO3)2��2
        }
    }
}

void expression(gg first, gg last, gg e) {//��+��������л�ѧʽ
    for (gg i = first, j = first; i <= last; i = j + 1) {
        j = equation.find('+', i);
        //һ���ӣ���Ϊ����'='��ߵ�ʽ�ӣ�last����equation��ĩβ��Ҫ��ֹ'='�ұ߿��ܵ�'+'�����е���ߣ�
        if (j == -1 or j > last)
            j = last + 1;
        handle(i, j - 1, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni;
    cin >> ni;
    while(ni--) {
        cin >> equation;
        ans.clear();
        gg length1 = equation.find('=');//��=������ʽ�ָ��������
        expression(0, length1-1, 1);
        expression(length1+1, equation.size()-1, -1);
        //������û��ԭ�Ӷ�Ӧ������Ϊ0
        auto i = find_if(ans.begin(), ans.end(), [](const pair<string, gg> p) { return p.second != 0; });
        cout << ((i == ans.end()) ? 'Y' : 'N') << '\n';
    }
    return 0;
}

//����ؼ���һֱ��֣���ֵ���С��