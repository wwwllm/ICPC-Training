#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector pre(n + 2, vector<int>(m + 2));
    auto add = [&](int x1, int y1, int x2, int y2)
    {
        int xmi = min(x1, x2), xma = max(x1, x2);
        int ymi = min(y1, y2), yma = max(y1, y2);
        if (xmi == xma || ymi == yma)
            return;
        pre[xma + 1][yma + 1]++;
        pre[xmi][ymi]++;
        pre[xma + 1][ymi]--;
        pre[xmi][yma + 1]--;
    };
    vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    vector t(n * m + 1, vector<array<int, 2>>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t[a[i][j]].push_back({i, j});
        }
    }
    for (int i = 1; i <= n * m; i++)
    {
        if (t[i].size() < 2)
            continue;
        vector<int> pre(n + 1, m + 1), suf(n + 1, 0);
        for (auto [x, y] : t[i])
        {
            pre[x] = min(pre[x], y);
            suf[x] = max(suf[x], y);
        }
        for (int i = 1; i <= n; i++)
        {
            pre[i] = min(pre[i - 1], pre[i]);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            suf[i] = max(suf[i + 1], suf[i]);
        }
        for (int i = 1; i + 1 <= n; i++)
        {
            int j = i + 1;
            int mi = pre[i], ma = suf[j];
            if (mi < ma)
                add(i, mi, j, ma);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pre[i][j] > 0)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
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