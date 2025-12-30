#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    bool ok = 1;
    if (n > 2 && ((s[1] == ')') || (s[n - 2] == '(')))
        ok = 0;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '(')
            res++;
        else
            res--;
        if (res == 0)
            cnt++;
    }
    if (cnt >= 2)
        ok = 0;
    cout << (ok ? "NO\n" : "YES\n");
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