#include <bits/stdc++.h>
using namespace std;

typedef struct element {
    int father;
    string lable, id;//标签和属性
}element;
vector<element> elements(105);//元素数
vector< vector<int> > levels(105);//层级

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ni, mi;
    string line;
    cin >> ni >> mi;
    getline(cin, line);//注意！！！cin不会自动换行！给坑死了
    int dot, space, level;
    for(int i = 1; i <= ni; ++i) {
        getline(cin, line);
        for(dot = 0; line[dot] == '.'; ++dot);
        for(space = dot; line[space] != ' ' && space < line.size(); ++space);
        elements[i].lable = line.substr(dot, space-dot);
        for(auto& c : elements[i].lable) {//重要,标签对大小写不敏感
            c = tolower(c);
        }
        elements[i].id = (space == line.size()) ? "" : line.substr(space+1);
        level = dot/2;
        levels[level].push_back(i);//在当前层级把当前行号压入,注意最顶层是第0层,而行号从1开始
        elements[i].father = (level-1 < 0) ? -1 : levels[level-1].back();
    }
/*    for(int i = 0; levels[i].size() >0; ++i) {
        for(auto& c : levels[i]) {
            cout << c << ' ';
        }
        cout << '\n';
    }*/
    while(mi--) {
        getline(cin, line);
        vector<string> query;
        string s;
        for(int i = 0; i < line.size(); ++i) {
            for(space = i; line[space] != ' ' && space < line.size(); ++space);
            s = line.substr(i, space-i);
            if(s[0] != '#') {//重要,标签对大小写不敏感
                for(auto& c : s)
                    c = tolower(c);
            }
            query.push_back(s);
            i = space;
        }
/*        for(auto& c : query) {
            cout << c << "23 ";
        }
        cout << '\n';*/
        vector<int> ans;//注意！！！使用vector等容器的时候要考虑回收利用，不能无脑定义在最前面！给坑死了
        for(int i = query.size()-1; levels[i].size() > 0; ++i) {//i代表从第几层开始搜索
            for(auto& row : levels[i]) {
                int j = query.size()-1;//j代表从选择器的最后一个后代开始搜索
                if(query[j] == elements[row].lable || query[j] == elements[row].id) {
                    --j;
                    for(int p = elements[row].father; p > -1 && j >= 0; p = elements[p].father) {
                        if(query[j] == elements[p].lable || query[j] == elements[p].id) {
                            --j;
                        }
                    }
                    if(j == -1) {
                        ans.push_back(row);
                    }
                }
            }
        }
        if(ans.size() != 0) {
            cout << ans.size() << ' ';
            for(auto& i : ans) {
                cout << i << ' ';
            }
        }
        else {
            cout << '0';
        }
        cout << '\n';
    }
    return 0;
}