#include <bits/stdc++.h>
using namespace std;

struct Basis
{
    vector<int> p, d;
    int cnt = 0;
    bool can_zero;
    int rank = 0;
    int m;
    Basis(int m) : m(m)
    {
        p.resize(m + 1), d.resize(m + 1);
        can_zero = 0;
    }
    // 插入元素
    void insert(long long x)
    {
        for (int i = m; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;
            if (!p[i])
            {
                p[i] = x;
                rank++;
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
        for (int i = m; i >= 0; i--)
        {
            res = max(res, res ^ p[i]);
        }
        return res;
    }
    // 合并线性基
    void merge(const Basis &b)
    {
        for (int i = m; i >= 0; i--)
        {
            if (b.p[i])
                insert(b.p[i]);
        }
    }
    void rebuild()
    {
        cnt = 0;
        for (int i = m; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if ((p[i] >> j) & 1)
                    p[i] ^= p[j];
            }
        }

        for (int i = 0; i <= 62; i++)
        {
            if (p[i])
                d[cnt++] = p[i];
        }
    }

    long long kth(long long k)
    {
        if (can_zero)
            k--; // 如果原集合能异或出0，第k小要减1
        if (k >= (1LL << cnt))
            return -1;
        long long res = 0;
        for (int i = 0; i < cnt; i++)
        {
            if ((k >> i) & 1)
                res ^= d[i];
        }
        return res;
    }
    vector<int> get()
    {
        vector<int> res{0};
        for (int i = 0; i < m; i++)
        {
            if (!p[i])
                continue;
            int siz = res.size();
            for (int j = 0; j < siz; j++)
            {
                res.push_back(res[j] ^ p[i]);
            }
        }
        return res;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n, Basis(m));
    vector s(n, vector<int>());
    vector<int> cnt(1 << m);
    for (int i = 0; i < n; i++)
    {
        int siz;
        cin >> siz;
        s[i].resize(siz);
        for (int j = 0; j < siz; j++)
        {
            cin >> s[i][j];
            g[i].insert(s[i][j]);
            cnt[s[i][j]]++;
        }
    }
    vector<int> w{0};
    vector<int> in(1 << m), vis(1 << m);
    in[0] = 1;
    for (int c = 1; c <= m; c++)
    {
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (auto x : s[i])
                cnt += in[x];
            int siz = s[i].size() + w.size() - cnt;
            if (siz == (1 << g[i].rank))
                continue;
            auto all = g[i].get();
            int need = -1;
            for (auto x : s[i])
                vis[x] = 1;
            for (auto x : all)
            {
                if (!vis[x] && !in[x])
                {
                    need = x;
                    break;
                }
            }
            assert(need != -1);
            for (auto x : s[i])
                vis[x] = 0;
            siz = w.size();
            for (int j = 0; j < siz; j++)
            {
                int x = need ^ w[j];
                in[x] = 1;
                w.push_back(x);
            }
            for (int j = 0; j < n; j++)
            {
                g[j].insert(need);
            }
        }
    }
    vector<int> ans;
    for (auto x : w)
    {
        if (cnt[x] < n)
            ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}