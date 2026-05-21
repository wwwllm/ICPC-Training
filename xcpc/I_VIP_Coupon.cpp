#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(0);
    }
    vector<array<int, 2>> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        q.push_back({a[i], inf});
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] >= c[i])
            continue;
        q.push_back({b[i], c[i]});
    }
    ranges::sort(q);
    for (int i = 0; i < q.size(); i++)
    {
        auto u = pq.top();
        pq.pop();
        if (u == inf)
            break;
        ans += max(0LL, q[i][0] - u);
        pq.push(max(u, q[i][1]));
    }
    cout << ans << '\n';
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