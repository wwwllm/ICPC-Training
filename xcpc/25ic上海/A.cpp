#include <bits/stdc++.h>
using namespace std;

struct LCA
{
    int n, l;
    vector<int> d;
    vector<vector<int>> f;
    vector<vector<int>> adj;

    LCA(int n) : n(n), l(__lg(n) + 1), d(n + 1), f(n + 1, vector<int>(l, 0)), adj(n + 1) {}

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void work(int rt = 1)
    {
        dfs(rt, 0);
    }

    void dfs(int u, int fa)
    {
        d[u] = d[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < l; i++)
        {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        for (int v : adj[u])
        {
            if (v != fa)
                dfs(v, u);
        }
    }

    int query(int u, int v)
    {
        if (d[u] < d[v])
            swap(u, v);
        for (int i = l - 1; i >= 0; i--)
        {
            if (d[f[u][i]] >= d[v])
                u = f[u][i];
        }
        if (u == v)
            return u;
        for (int i = l - 1; i >= 0; i--)
        {
            if (f[u][i] != f[v][i])
            {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    }

    int dist(int u, int v)
    {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }
};
int randINT(int l, int r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> fa(n + 1);
    LCA adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        if (fa[i])
            adj.add(fa[i], i);
    }
    vector<int> p(n);
    ranges::iota(p, 1);
    int cnt = 0;
    auto query = [&](int u, int d) -> bool
    {
        cnt++;
        cout << "? " << u << ' ' << d << endl;
        int res;
        cin >> res;
        return res;
    };
    adj.work();
    while (p.size() > 1 && cnt < 40)
    {
        int m = p.size();
        int pos = randINT(0, m - 1);
        int u = p[pos];
        ranges::sort(p, [&](int a, int b)
                     { return adj.dist(a, u) < adj.dist(b, u); });
        int d;
        int cnt = 0;
        for (int i = 0, j = 0; i < m;)
        {
            j = i;
            int tmp = adj.dist(p[i], u);
            while (j < p.size() && tmp == adj.dist(p[j], u))
                j++;
            if (cnt + j - i > p.size() / 2)
            {
                if (i > 0 &&
                    min(i, m - i) > min(j, m - j))
                {
                    d = adj.dist(p[i - 1], u);
                }
                else
                {
                    d = tmp;
                }
                break;
            }
            cnt += j - i;
            i = j;
        }
        int res = query(u, d);
        vector<int> np;
        for (int i = 0; i < m; i++)
        {
            int v = p[i];
            if (adj.dist(u, v) <= d == res)
                np.push_back(v);
        }
        p = np;
    }
    auto answer = [&](int u)
    {
        cout << "! " << u << endl;
    };
    answer(p[0]);
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