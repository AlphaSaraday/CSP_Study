#include <bits/stdc++.h>
using namespace std;

typedef struct element {
    int father;
    string lable, id;//��ǩ������
}element;
vector<element> elements(105);//Ԫ����
vector< vector<int> > levels(105);//�㼶

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ni, mi;
    string line;
    cin >> ni >> mi;
    getline(cin, line);//ע�⣡����cin�����Զ����У���������
    int dot, space, level;
    for(int i = 1; i <= ni; ++i) {
        getline(cin, line);
        for(dot = 0; line[dot] == '.'; ++dot);
        for(space = dot; line[space] != ' ' && space < line.size(); ++space);
        elements[i].lable = line.substr(dot, space-dot);
        for(auto& c : elements[i].lable) {//��Ҫ,��ǩ�Դ�Сд������
            c = tolower(c);
        }
        elements[i].id = (space == line.size()) ? "" : line.substr(space+1);
        level = dot/2;
        levels[level].push_back(i);//�ڵ�ǰ�㼶�ѵ�ǰ�к�ѹ��,ע������ǵ�0��,���кŴ�1��ʼ
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
            if(s[0] != '#') {//��Ҫ,��ǩ�Դ�Сд������
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
        vector<int> ans;//ע�⣡����ʹ��vector��������ʱ��Ҫ���ǻ������ã��������Զ�������ǰ�棡��������
        for(int i = query.size()-1; levels[i].size() > 0; ++i) {//i����ӵڼ��㿪ʼ����
            for(auto& row : levels[i]) {
                int j = query.size()-1;//j�����ѡ���������һ�������ʼ����
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