#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2033/E
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[a[i]] = i;
    int ans = 0;
    auto Swap = [&](int i, int j) -> void
    {
        swap(a[i], a[j]);
        swap(p[a[i]], p[a[j]]);
        ans++;
    };
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
            continue;
        else
        {
            int u = p[i];
            if (u == a[i])
                continue;
            else
            {
                int v = a[i];
                Swap(u, v);
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << p[i] << ' ';
        // cout << '\n';
    }
    cout << ans << '\n';
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