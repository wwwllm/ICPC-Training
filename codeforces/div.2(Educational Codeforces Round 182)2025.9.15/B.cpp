#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i])
            s.erase(p[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        if (p[i] == 0)
        {
            p[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != i)
        {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (p[i] != i)
        {
            r = i;
            break;
        }
    }
    if (r == l)
    {
        cout << 0 << '\n';
    }
    else
        cout << r - l + 1 << '\n';
    return;
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