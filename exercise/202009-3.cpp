#include <bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg MAX = 1e3;
gg qi, mi, ni, ki, Si, si;//��������������������������������ÿ�����������������������ݸ���, �����
pair< string, vector<gg> > device[MAX];//�豸��Ϣ
vector<gg> gragh[MAX];//���ڹ��������޻�ͼDAG���ܼ򵥵�
gg degree[MAX];//���(��i���豸�������ж��ٸ����������豸�����)
bool output[MAX];//���
vector<gg> top;//�洢��������
//����������
bool topsort() {
    queue<gg> q;    //�������Ϊ0�Ķ���
    for(gg i = 1; i <= ni; ++i) {   //�����Ϊ��Ķ�����������
        if(degree[i] == 0)  q.push(i);
    }
    while(!q.empty()) {
        gg p = q.front();
        q.pop();
        top.push_back(p);
        for(auto i : gragh[p]) {    //�����ý����ڽӶ���
            --degree[i];    //�����ڽӶ������ȣ�������Ϊ����ѹ�����
            if(degree[i] == 0)  q.push(i);
        }
    }
    return top.size() == (size_t)ni;
}
//��input���룬����������������
void get_result(vector<gg>& input) {
    for(auto i : top) {
        if(device[i].first == "NOT") {
            gg j = device[i].second[0];
            output[i] = !(j > 0 ? output[j] : input[-j]);
        }
        else if(device[i].first == "AND") {
            output[i] = true;
            for(auto j : device[i].second) {
                output[i] &= j > 0 ? output[j] : input[-j];
            }
        }
        else if(device[i].first == "OR") {
            output[i] = false;
            for(auto j : device[i].second) {
                output[i] |= j > 0 ? output[j] : input[-j];
            }
        }
        else if(device[i].first == "XOR") {
            output[i] = false;
            for(auto j : device[i].second) {
                output[i] ^= j > 0 ? output[j] : input[-j];
            }
        }
        else if(device[i].first == "NAND") {
            output[i] = true;
            for(auto j : device[i].second) {
                output[i] &= j > 0 ? output[j] : input[-j];
            }
            output[i] = !output[i];
        }
        else if(device[i].first == "NOR") {
            output[i] = false;
            for(auto j : device[i].second) {
                output[i] |= j > 0 ? output[j] : input[-j];
            }
            output[i] = !output[i];
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> qi;//������
    while(qi--) {
        cin >> mi >> ni;//��������������
        //init��ʼ�����������Ҫ����ʱ���������һ������Ĳ���
        for(gg i = 1; i <= ni; ++i) {//�õ�ni�ͳ�ʼ����ni����
            device[i].second.clear();
            gragh[i].clear();
            degree[i] = 0;
        }
        top.clear();
        //����DAGͼ���洢�豸��Ϣ����¼���
        string s;//�ݴ�Ii, Oi
        for(gg i = 1; i <= ni; ++i) {
            cin >> device[i].first >> ki;
            while(ki--) {
                cin >> s;
                gg num = stoll(s.substr(1));
                if(s[0] == 'O') {
                    ++degree[i];
                    gragh[num].push_back(i);
                    device[i].second.push_back(num);
                }
                else    device[i].second.push_back(-num);
            }
        }
        //�ж��Ƿ��л�
        bool judge = topsort();
        if(!judge)  cout << "LOOP" << "\n";//ע�⣡�˴�������continueͼ���㣬��Ϊ�����ֹһ������Ҫ������ôǰһ�����������û�ж��겻��ֱ���Ե���Ӧ�ö�ȡ���ǲ�����/�����
        //������������ͽ�����
        cin >> Si;
        vector< vector<gg> > input(Si+1, vector<gg>(mi + 1));//���������ȫ����ã���Ϊ�������������������ʽ���ܱ�
        for(gg j = 1; j <= Si; ++j) {
            for(gg i = 1; i <= mi; ++i) cin >> input[j][i];
        }
        for(gg j = 1; j <= Si; ++j) {
            cin >> si;
            gg k;
            if(!judge) {
                while(si--) cin >> k;
            }
            else {
                get_result(input[j]);
                while(si--) {
                    cin >> k;
                    cout << output[k];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}

//˼·�������޻�ͼ->��������(�������Ҫ��¼)�ж����޻������Ұ�������˳�����������