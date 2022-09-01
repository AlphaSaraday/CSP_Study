#include <bits/stdc++.h>
using namespace std;
using gg = long long;
constexpr gg MAX = 1e3;
gg qi, mi, ni, ki, Si, si;//问题数，输入数，器件数，测试数，每个器件的输入数，测试数据个数, 输出数
pair< string, vector<gg> > device[MAX];//设备信息
vector<gg> gragh[MAX];//用于构建有向无环图DAG，很简单的
gg degree[MAX];//入度(第i个设备的输入有多少个来自其他设备的输出)
bool output[MAX];//输出
vector<gg> top;//存储拓扑序列
//求拓扑序列
bool topsort() {
    queue<gg> q;    //储存入度为0的顶点
    for(gg i = 1; i <= ni; ++i) {   //将入度为零的顶点放入队列中
        if(degree[i] == 0)  q.push(i);
    }
    while(!q.empty()) {
        gg p = q.front();
        q.pop();
        top.push_back(p);
        for(auto i : gragh[p]) {    //遍历该结点的邻接顶点
            --degree[i];    //减少邻接顶点的入度，如果入度为零则压入队列
            if(degree[i] == 0)  q.push(i);
        }
    }
    return top.size() == (size_t)ni;
}
//按input输入，求出所有器件的输出
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
    cin >> qi;//问题数
    while(qi--) {
        cin >> mi >> ni;//输入数，器件数
        //init初始化：多个问题要处理时，清除掉上一个问题的残留
        for(gg i = 1; i <= ni; ++i) {//用到ni就初始化到ni够了
            device[i].second.clear();
            gragh[i].clear();
            degree[i] = 0;
        }
        top.clear();
        //构造DAG图，存储设备信息，记录入度
        string s;//暂存Ii, Oi
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
        //判断是否有环
        bool judge = topsort();
        if(!judge)  cout << "LOOP" << "\n";//注意！此处不能用continue图方便，因为如果不止一个问题要处理，那么前一个问题的数据没有读完不能直接略掉，应该读取但是不处理/输出！
        //测试数据输入和结果输出
        cin >> Si;
        vector< vector<gg> > input(Si+1, vector<gg>(mi + 1));//输入必须先全部存好，因为输出集中在最后，且输出方式可能变
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

//思路：有向无环图->拓扑排序(则入度需要记录)判定有无环，并且按照排序顺序来计算输出