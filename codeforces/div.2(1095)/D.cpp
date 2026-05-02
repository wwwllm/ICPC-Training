#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> e, o;
    int mio = 1e9, mao = 0, mie = 1e9, mae = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            o.push_back(x);
            mio = min(mio, x);
            mao = max(mao, x);
        }
        else
        {
            e.push_back(x);
            mie = min(x, mie);
            mae = max(x, mae);
        }
    }
    n = e.size();
    int m = o.size();
    int cur = -1;
    if (e.size())
    {
        cur = e[0];
        for (int i = 1; i < n; i++)
        {
            if (e[i] >= cur)
            {
                cur = e[i];
                continue;
            }
            if (mio < e[i] || mao > cur)
                continue;
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    if (o.size())
    {
        cur = o[0];
        for (int i = 1; i < m; i++)
        {
            if (o[i] >= cur)
            {
                cur = o[i];
                continue;
            }
            if (mie < o[i] || mae > cur)
                continue;
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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