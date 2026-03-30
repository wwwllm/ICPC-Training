#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    set<array<int, 2>> s;
    queue<int> q;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)
        {
            s.insert({a[i], i});
            vis[i] = 1;
        }
        else
        {
            q.push(i);
        }
    }
    while (m)
    {
        if (vis[p] == 1)
        {
            if (m < a[p])
                break;
            ans++;
            m -= a[p];
            s.erase({a[p], p});
            vis[p] = 0;
            q.push(p);
            auto u = q.front();
            q.pop();
            s.insert({a[u], u});
            vis[u] = 1;
        }
        else
        {
            auto [val, idx] = *s.begin();
            if (m < val)
                break;
            s.erase(s.begin());
            m -= val;
            vis[idx] = 0;
            q.push(idx);
            auto u = q.front();
            q.pop();
            vis[u] = 1;
            s.insert({a[u], u});
        }
    }
    cout << ans << '\n';
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