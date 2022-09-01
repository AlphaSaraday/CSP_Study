#include <bits/stdc++.h>
using namespace std;
using gg = long long;
#define rep(i, a, b, c) for (gg i = (a); i <= (b); i += (c))
#define rrep(i, a, b, c) for (gg i = (a); i >= (b); i -= (c))
constexpr gg MAX = 1e6 + 5;
constexpr gg mod = 1e9 + 7;
constexpr gg INF = 2e18;
constexpr double thre = 1e-7;
constexpr gg nmax = 105, mkmax = 15;
using ag = array<gg, 2>;
gg ti, ni, mi, ki, di, pi, xi, yi;
vector<ag> tree[nmax];
bool food[nmax][mkmax];
gg dp1[nmax][mkmax], dp2[nmax][1 << mkmax], dp3[mkmax][1 << mkmax];
ag dfs(gg root, gg fa, gg k) {
    gg ans = 0, m = 0;
    for (auto& i : tree[root]) {
        if (i[0] == fa) {
            continue;
        }
        ag c = dfs(i[0], root, k);
        if (c == ag{-1, -1}) {
            continue;
        }
        ans += c[0] + i[1] * 2;
        m = max(m, i[1] + c[1]);
    }
    if (m == 0) {
        return food[root][k] ? ag{0, 0} : ag{-1, -1};
    }
    return {ans, m};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> ni >> mi >> ki;
    rep(i, 1, ni, 1) {
        rep(j, 1, ki, 1) { cin >> food[i][j]; }
    }
    rep(i, 1, ni - 1, 1) {
        gg a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    rep(i, 1, ni, 1) {
        rep(j, 1, ki, 1) {
            auto ans = dfs(i, -1, j);
            dp1[i][j] = ans[0] - ans[1];
        }
    }
    gg s = (1 << ki) - 1;
    rep(i, 1, ni, 1) {
        rep(j, 1, s, 1) {
            rep(k, 0, ki - 1, 1) {
                if (j & (1 << k)) {
                    dp2[i][j] = max(dp2[i][j], dp1[i][k + 1]);
                }
            }
        }
    }
    memset(dp3, 0x3f, sizeof(dp3));
    dp3[0][0] = 0;
    gg ans = INF;
    rep(i, 1, ni, 1) {
        rep(j, 1, mi, 1) {
            rrep(k, s, 1, 1) {
                for (gg t = k; t != 0; t = (t - 1) & k) {
                    dp3[j][k] = min(dp3[j][k], max(dp2[i][t], dp3[j - 1][t ^ k]));
                }
            }
            ans = min(ans, dp3[j][s]);
        }
    }
    cout << ans << "\n";
    return 0;
}