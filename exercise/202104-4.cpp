#include<bits/stdc++.h>
using namespace std;
using gg = long long;
#define rep(i, a, b, c) for (gg i = (a); i <= (b); i += (c))
#define rrep(i, a, b, c) for (gg i = (a); i >= (b); i -= (c))
constexpr gg MAX = 1e3 + 5;
constexpr gg MAX2 = 1e5 + 5;
constexpr gg mod = 1e9 +7;
//constexpr gg INF = 2e18;//infinity
//constexpr double thre = 1e-7;//threshold
gg ni;
gg a[MAX], dp[MAX];
vector<gg> factor[MAX2];
void getFactor(gg n) {  //�ҳ�2~nÿ���������С������Լ�����ֱ�����factor[i]����䳤������
    for (gg i = 1; i < n; ++i) {
        factor[i].push_back(1);
        for (gg j = 2; j * j <= i; ++j) {    //�ҳ�i�����С������Լ����ֻ���жϵ�����i
            if (i % j ==0) {
                factor[i].push_back(j);
                if (j *j != i)  factor[i].push_back(i / j); //���ڸ���i��Լ����С�ڸ���i��Լ������
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getFactor(MAX2);
    cin >> ni;
    rep(i, 1, ni, 1) {
        cin >> a[i];
        dp[i] = 0;
    }
    dp[1] = 1;  //�����߽�����
    //�ؼ��㷨����ʼdp
    rep(i, 2, ni, 1) {
        set<gg> fa;//��¼���ֵ�����
        rrep(j, i-1, 1, 1) {
            gg x = a[i] - a[j], res=0;
            for (gg t : factor[x]) {
                if (not fa.count(t)) {  //set::count(element):����Ԫ���ڼ����г��ֵĴ���������set����������ΨһԪ�أ����ֻ�ܷ���1��0
                    fa.insert(t);
                    ++res;
                }
            }
            fa.insert(x);   //ע�⣬�Լ�����Ҳ���Լ���Լ����������ҲҪ���ȥ������������Լ���ͼ�������
                            //���ϰ���λ��Ϊ0,2,4,10,��������[4,10]����������Ϊ1,2,3���ټ�������[2,10]����������ʱ����������1,2,3,6
                            //��Ϊ��ȡ1,2,3,6��Ȼ�������ϰ���4����������
            dp[i] = (dp[i] + res * dp[j]) % mod;
        }
    }
    cout << dp[ni] << "\n";
    return 0;
}

//����ؼ�����md�ĵ�