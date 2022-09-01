#include <bits/stdc++.h>
using namespace std;
using gg = long long;
string equation;
unordered_map<string, gg> ans;

//注意这个引用，函数调用完时first已经指向数字后(有数字的话)的第一个元素字母
gg digits(gg& first, gg last) {
    gg e = 0;
    for(; first <= last and isdigit(equation[first]); ++first) {
        e = 10 * e + equation[first] - '0';
    }
    return (e > 0) ? e : 1;
}

//计算formula的[first,last]区间的原子及其对应系数，基本系数为e
void handle(gg first, gg last, gg e) {
    //递归终点：单个原子
    if((first == last) or (first + 1 == last and islower(equation[last]))) {
        ans[equation.substr(first, last - first + 1)] += e;
        return;//记得return
    }
    //开始处理分解当前式子
    e *= digits(first, last);//当前式子内所有原子基本系数要乘上当前式子起始系数
    for(gg i = first, j = i+1; i <= last; i = j, ++j) {
        if(isupper(equation[i])) { //无括号，一个一个元素/原子处理
            if(j <= last and islower(equation[j])) {
                ++j;
            }
            gg k = j;//这里很重要！必须要把j的值存起来，不然在下一步handle执行之前，先执行了digits会更改j的值！
            handle(i, k-1, e*digits(j, last));//已经递归到终点，digits(j, last)是计算倍数，如Cl2的2
        }
        else if(equation[i] == '(') { //有括号，括号内的所有东西当做新的当前式递归处理
            gg num = 1;
            while(num != 0){
                if(equation[j] == '(')          ++num;
                else if(equation[j] == ')')     --num;
                ++j;
            }
            gg k = j;
            handle(i+1, k-1, e*digits(j, last));//digits(j, last)是计算倍数，如(PO3)2的2
        }
    }
}

void expression(gg first, gg last, gg e) {//按+分离出所有化学式
    for (gg i = first, j = first; i <= last; i = j + 1) {
        j = equation.find('+', i);
        //一个坑！因为对于'='左边的式子，last不是equation的末尾！要防止'='右边可能的'+'被误判到左边！
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
        gg length1 = equation.find('=');//按=将方程式分割成两部分
        expression(0, length1-1, 1);
        expression(length1+1, equation.size()-1, -1);
        //查找有没有原子对应个数不为0
        auto i = find_if(ans.begin(), ans.end(), [](const pair<string, gg> p) { return p.second != 0; });
        cout << ((i == ans.end()) ? 'Y' : 'N') << '\n';
    }
    return 0;
}

//本题关键：一直拆分，拆分到最小处