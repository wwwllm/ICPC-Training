#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    SCC() {};
    SCC(int n)
    {
        init(n);
    }
    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        cur = cnt = 0;
    }
    void add(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int u)
    {
        dfn[u] = low[u] = cur++;
        stk.push_back(u);
        for (auto v : adj[u])
        {
            if (dfn[v] == -1)
            {
                dfs(v);
                low[u] = min(low[v], low[u]);
            }
            else if (bel[v] == -1)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            int v;
            do
            {
                v = stk.back();
                stk.pop_back();
                bel[v] = cnt;
            } while (v != u);
            cnt++;
        }
    }
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
                dfs(i);
        }
        return bel;
    }
    vector<vector<int>> get_DAG()
    {
        vector nadj(cnt, vector<int>{});
        for (int u = 0; u < n; u++)
        {
            for (auto v : adj[u])
            {
                if (bel[u] != bel[v])
                    nadj[bel[u]].push_back(bel[v]);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            ranges::sort(nadj[i]);
            nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
        }
        return nadj;
    }
};
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector p(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> p[i][j], p[i][j]--;
    }
    SCC adj(n);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            adj.add(p[i][j], p[i][j + 1]);
        }
    }
    auto rnk = adj.work();
    vector bel(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bel[i][j] = rnk[p[i][j]];
        }
    }
    vector L(k, vector<int>(n, n));
    vector R(k, vector<int>(n, -1));
    int m = adj.cnt;
    vector<int> nxt(m);
    for (int i = 0; i < k; i++)
    {
        nxt.assign(m, n);
        for (int j = 0; j < n; j++)
        {
            nxt[bel[i][j]] = min(nxt[bel[i][j]], j);
            L[i][j] = nxt[bel[i][j]];
        }
    }
    for (int i = 0; i < k; i++)
    {
        nxt.assign(m, -1);
        for (int j = n - 1; j >= 0; j--)
        {
            nxt[bel[i][j]] = max(nxt[bel[i][j]], j);
            R[i][j] = nxt[bel[i][j]];
        }
    }
    vector pre(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int d = j - L[i][j] + 1;
            pre[i][j] = d * (d - 1);
            if (L[i][j] != 0)
                pre[i][j] += pre[i][L[i][j] - 1];
        }
    }
    int key = 0;
    auto calc = [&](int &id, int &l, int &r) -> void
    {
        id = (id + key) % k;
        l = (l + key) % n;
        r = (r + key) % n;
    };
    while (q--)
    {
        int id, l, r;
        cin >> id >> l >> r;
        calc(id, l, r);
        int ll = R[id][l];
        if (ll < r)
        {
            key = pre[id][r] - pre[id][ll] + (ll - l) * (ll - l + 1);
        }
        else
        {
            key = (r - l) * (r - l + 1);
        }
        key /= 2;
        cout << key << '\n';
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