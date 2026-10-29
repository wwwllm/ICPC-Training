#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
struct DSU
{
    vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x)
    {
        return x == f[x] ? f[x] : f[x] = find(f[x]);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }
};
void solve()
{
    int n, m, k, Q;
    cin >> n >> m >> k >> Q;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto get_idx = [&](int i, int j)
    {
        return i * m + j;
    };
    DSU dsu(n * m + 1);
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
                continue;
            for (auto [dx, dy] : walk)
            {
                int ni = i + dx, nj = j + dy;
                if (ni > 0 && ni < n && nj > 0 && nj < m && a[ni][nj] != '#')
                    dsu.merge(get_idx(i, j), get_idx(ni, nj));
            }
        }
    }
    vector<int> p;
    vector<array<int, 2>> e;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int p1 = get_idx(x1, y1), p2 = get_idx(x2, y2);
        p1 = dsu.find(p1), p2 = dsu.find(p2);
        p.push_back(p1), p.push_back(p2);
        e.push_back({p1, p2});
    }
    ranges::sort(p);
    p.erase(unique(p.begin(), p.end()), p.end());
    int N = p.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < N; i++)
    {
        pos[p[i]] = i;
    }
    vector adj(N, vector<int>());
    for (auto [p1, p2] : e)
    {
        int u = pos[p1], v = pos[p2];
        adj[u].push_back(v);
    }
    vector vis(N, vector<int>(N));
    auto bfs = [&](int s)
    {
        queue<int> q;
        q.push(s);
        vis[s][s] = 1;
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (vis[s][v])
                    continue;
                vis[s][v] = 1;
                q.push(v);
            }
        }
    };
    for (int i = 0; i < N; i++)
    {
        bfs(i);
    }
    while (Q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int p1 = get_idx(x1, y1), p2 = get_idx(x2, y2);
        p1 = dsu.find(p1), p2 = dsu.find(p2);
        if (p1 == p2)
        {
            cout << "1\n";
            continue;
        }
        if (!pos.count(p1) || !pos.count(p2))
        {
            cout << 0 << '\n';
            continue;
        }
        int u = pos[p1], v = pos[p2];
        if (vis[u][v])
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}