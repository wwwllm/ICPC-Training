#include <bits/stdc++.h>
#define pb push_back
using namespace std;

using i64 = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (s.size() && a[s.back()] <= a[i])
        {
            s.pop_back();
        }
        if (s.size())
            l[i] = s.back();
        else
            l[i] = 0;
        s.pb(i);
    }
    s.clear();
    for (int i = n; i >= 1; i--)
    {
        while (s.size() && a[s.back()] >= a[i])
        {
            s.pop_back();
        }
        if (s.size())
            r[i] = s.back();
        else
            r[i] = n + 1;
        s.pb(i);
    }

    vector<int> f(n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (l[i] != 0 && r[i] != n + 1)
        {
            f[l[i]] = min(f[l[i]], r[i]);
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        f[i] = min(f[i + 1], f[i]);
    }
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        if (f[L] > R)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}