#include <bits/stdc++.h>
using namespace std;

const int N = 26;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++)
    {
        z[i] = max(0, min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > j + z[j])
            j = i;
    }
    vector<array<int, 2>> e;
    for (int i = 1; i < n; i++)
    {
        int j = z[i];
        if (i + j == n)
        {
            cout << 0 << '\n';
            return;
        }
        int u = s[j] - 'a', v = s[i + j] - 'a';
        e.push_back({v, u});
    }
    ranges::sort(e);
    e.erase(unique(e.begin(), e.end()), e.end());
    vector adj(N + 1, vector<int>());
    vector<int> ind(N + 1);
    for (auto [u, v] : e)
    {
        adj[u].push_back(v);
        ind[v]++;
    }
    {
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (ind[v] == 0)
                    continue;
                ind[v]--;
                if (ind[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < N; i++)
        {
            if (ind[i] != 0)
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    int m = (1LL << N);
    vector<unsigned int> dp(m);
    vector<int> pre(N);
    for (int i = 0; i < N; i++)
    {
        for (auto v : adj[i])
        {
            pre[i] |= (1LL << v);
        }
    }
    dp[0] = 1;
    for (int mask = 0; mask < m; mask++)
    {
        if (dp[mask] == 0)
            continue;
        for (int u = 0; u < N; u++)
        {
            if (mask >> u & 1)
                continue;
            if ((pre[u] & mask) == pre[u])
            {
                dp[mask | (1LL << u)] += dp[mask];
            }
        }
    }
    cout << dp[m - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}