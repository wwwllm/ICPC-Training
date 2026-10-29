#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;
void solve()
{
    string s;
    cin >> s;
    if (s[0] == s[2])
        cout << "No\n";
    else if (s[1] == '+' || s[1] == '*' || s[0] == '0')
        cout << "Yes\n";
    else
        cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}