#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector adj(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        deg[i] = adj[i].size();
    }

    int M = 1 << m;
    vector<int> mask(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int siz;
        cin >> siz;
        int msk = 0;
        for (int j = 0; j < siz; j++)
        {
            int bit;
            cin >> bit;
            bit--;
            msk |= 1 << bit;
        }
        mask[i] = msk;
    }
    if (n == 2)
    {
        cout << "0 0\n";
        return;
    }

    int U = 0;
    vector<int> Leaf(n + 1);
    int L = 0;
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] > 1)
            U |= mask[i], root = i;
        else
            Leaf[i] = 1, L++;
    }

    vector down(n + 1, vector<int>(M));
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        if (Leaf[u])
            down[u][mask[u]]++;
        for (auto v : adj[u])
        {
            if (f == v)
                continue;
            self(self, v, u);
            for (int i = 0; i < M; i++)
            {
                int msk = i | mask[u];
                down[u][msk] += down[v][i];
            }
        }
    };
    dfs1(dfs1, root, -1);

    vector up(n + 1, vector<int>(M));

    auto dfs2 = [&](auto &&self, int u, int f) -> void
    {
        for (auto v : adj[u])
        {
            if (f == v)
                continue;
            for (int i = 0; i < M; i++)
            {
                int msk = i | mask[v];
                up[v][msk] += up[u][i];
            }
            vector<int> cnt = down[u];
            for (int i = 0; i < M; i++)
            {
                int j = i | mask[u];
                cnt[j] -= down[v][i];
            }
            for (int i = 0; i < M; i++)
            {
                int msk = i | mask[v];
                up[v][msk] += cnt[i];
            }
            self(self, v, u);
        }
    };
    dfs2(dfs2, root, -1);

    // for (int i = 1; i <= n; i++)
    //     cerr << mask[i] << " \n"[i == n];

    // for (int i = 1; i <= n; i++)
    // {
    //     cerr << i << ' ' << "down:" << '\n';
    //     for (int j = 0; j < M; j++)
    //     {
    //         cerr << down[i][j] << " \n"[j == M - 1];
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            int nL = L - 1;
            int nU = U | mask[i];
            int cnt = 0;
            for (int st = 0; st < M; st++)
            {
                if ((st & nU) == nU)
                {
                    cnt = max(cnt, up[i][st]);
                }
            }
            cout << nL - cnt << " \n"[i == n];
        }
        else
        {
            int cnt = 0;
            for (int st = 0; st < M; st++)
            {
                if ((st & U) == U)
                {
                    cnt = max(cnt, down[i][st] + up[i][st]);
                }
            }
            cout << L - cnt << " \n"[i == n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}