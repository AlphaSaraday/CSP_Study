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
void getFactor(gg n) {  //找出2~n每个数的所有≤自身的约数，分别存放在factor[i]这个变长数组中
    for (gg i = 1; i < n; ++i) {
        factor[i].push_back(1);
        for (gg j = 2; j * j <= i; ++j) {    //找出i的所有≤自身的约数，只需判断到根号i
            if (i % j ==0) {
                factor[i].push_back(j);
                if (j *j != i)  factor[i].push_back(i / j); //大于根号i的约数用小于根号i的约数来求
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
    dp[1] = 1;  //设立边界条件
    //关键算法，开始dp
    rep(i, 2, ni, 1) {
        set<gg> fa;//记录出现的因子
        rrep(j, i-1, 1, 1) {
            gg x = a[i] - a[j], res=0;
            for (gg t : factor[x]) {
                if (not fa.count(t)) {  //set::count(element):返回元素在集合中出现的次数。由于set容器仅包含唯一元素，因此只能返回1或0
                    fa.insert(t);
                    ++res;
                }
            }
            fa.insert(x);   //注意，自己本身也是自己的约数，在这里也要算进去！如果不懂，自己画图举例理解
                            //如障碍物位置为0,2,4,10,计算区间[4,10]的种树公差为1,2,3后，再计算区间[2,10]的种树公差时，必须弃掉1,2,3,6
                            //因为若取1,2,3,6必然会碰到障碍物4。其余类推
            dp[i] = (dp[i] + res * dp[j]) % mod;
        }
    }
    cout << dp[ni] << "\n";
    return 0;
}

//本题关键：见md文档