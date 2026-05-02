#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Basis
{
    long long p[32], d[32];
    int cnt = 0;
    bool can_zero;
    Basis()
    {
        memset(p, 0, sizeof(p));
        can_zero = 0;
    }
    // 插入元素
    void insert(long long x)
    {
        for (int i = 31; i >= 0; i--)
        {
            if (!(x >> i))
                continue;
            if (!p[i])
            {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
        can_zero = 1;
    }
    // 查询最大异或值
    long long query()
    {
        long long res = 0;
        for (int i = 31; i >= 0; i--)
        {
            res = max(res, res ^ p[i]);
        }
        return res;
    }
    long long get_min(long long x)
    {
        for (int i = 31; i >= 0; i--)
        {
            if ((x ^ p[i]) < x)
                x ^= p[i];
        }
        return x;
    }
};
struct Trie01
{
    vector<array<int, 2>> nxt;
    vector<int> cnt, pass;
    int L; // 最大位数

    Trie01(int max_bit = 30) : L(max_bit)
    {
        init();
    };

    void init()
    {
        nxt.assign(1, {-1, -1}); // 使用-1表示空节点
        cnt.assign(1, 0);
        pass.assign(1, 0);
    }

    void insert(int val)
    {
        int p = 0;
        for (int i = L; i >= 0; --i)
        {
            int x = (val >> i) & 1;
            if (nxt[p][x] == -1)
            {
                nxt[p][x] = nxt.size();
                nxt.push_back({-1, -1});
                cnt.push_back(0);
                pass.push_back(0);
            }
            pass[p]++;
            p = nxt[p][x];
        }
        cnt[p]++;
        pass[p]++;
    }
    int query(int k, int val)
    {
        int p = 0;
        int ans = 0;
        for (int i = L; i >= 0; i--)
        {
            if (p == -1)
                break;
            int x = (k >> i) & 1;
            int y = (val >> i) & 1;
            if (x == 1)
            {
                if (nxt[p][y] != -1)
                    ans += pass[nxt[p][y]];
                p = nxt[p][!y];
            }
            else
                p = nxt[p][y];
        }
        if (p != -1)
            ans += pass[p];
        return ans;
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> vis(n + 1), dis(n + 1);
    Basis B;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        vis[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (v == f)
                continue;
            if (vis[v])
                B.insert(w ^ dis[u] ^ dis[v]);
            else
            {
                dis[v] = dis[u] ^ w;
                self(self, v, u);
            }
        }
    };
    dfs(dfs, 1, 0);
    Trie01 T(32);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int val = B.get_min(dis[i]);
        ans += T.query(k, val);
        T.insert(val);
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