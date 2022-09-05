#include <bits/stdc++.h>
#include <regex>
using namespace std;
using gg = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    gg ni, mi;
    cin >> ni >> mi;
    vector< pair<regex, string> > rule;
    string pi, ri, qi;
    while(ni--) {
        cin >> pi >> ri;
        pi = regex_replace(pi, regex("<int>"), "(\\d+)");
        pi = regex_replace(pi, regex("<str>"), "([^/]+)");
        pi = regex_replace(pi, regex("<path>"), "(.+)");
        rule.push_back({regex(pi), ri});
    }
    smatch result;
    bool hint;
    while(mi--) {
        cin >> qi;
        hint = false;
        for(auto& i : rule) {
            if(regex_match(qi, result, i.first)) {
                hint = true;
                cout << i.second;
                for(gg j = 1; j < result.size(); ++j) {
                    if(regex_match(result.str(j), regex("\\d+"))) {
                        cout << " " << stoll(result.str(j));
                    }
                    else cout << " " << result.str(j);
                }
                cout << '\n';
                break;
            }
        }
        if(!hint) cout << "404" << '\n';
    }
    return 0;
}
