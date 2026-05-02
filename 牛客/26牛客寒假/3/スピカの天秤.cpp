#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int suma = 0, sumb = 0;
    for (auto &x : a)
        cin >> x, suma += x;
    for (auto &x : b)
        cin >> x, sumb += x;
    ranges::sort(a, greater<int>());
    ranges::sort(b, greater<int>());
    if (suma == sumb)
        cout << 1 << '\n';
    else if (suma > sumb)
    {
        int cnt = 0, d = suma - sumb;
        for (int i = 0; i < n; i++)
        {
            if (d > 0)
            {
                cnt++, d -= a[i];
            }
            else
                break;
        }
        cout << cnt << '\n';
    }
    else
    {
        int cnt = 0, d = sumb - suma;
        for (int i = 0; i < m; i++)
        {
            if (d > 0)
            {
                cnt++, d -= b[i];
            }
            else
                break;
        }
        cout << cnt << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}