#include <bits/stdc++.h>
#define int long long
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
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
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
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    long long g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g; // ax + by = gcd(a, b)
}
bool merge_crt(long long &a1, long long &m1, long long a2, long long m2)
{
    long long x, y;
    long long g = exgcd(m1, m2, x, y);
    long long c = a2 - a1;
    if (c % g)
        return false; // 差值不能被 gcd 整除，无解

    long long mod = m2 / g;
    x = (__int128)x * (c / g) % mod;
    a1 += x * m1;
    m1 *= mod; // 新模数为 lcm(m1, m2)
    a1 = (a1 % m1 + m1) % m1;
    return true;
}

// equations: {余数, 模数}
pair<long long, long long> excrt(const vector<pair<long long, long long>> &equations)
{
    long long a = equations[0].first;
    long long m = equations[0].second;
    for (int i = 1; i < (int)equations.size(); i++)
    {
        if (!merge_crt(a, m, equations[i].first, equations[i].second))
            return {-1, -1};
    }
    return {a, m}; // x = a (mod m)
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    auto change = [&]()
    {
        vector<int> aa(n + 1);
        for (int i = 1; i <= n; i++)
            aa[i] = a[a[i]];
        a = aa;
    };
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }
    int D = 10;
    for (int i = 1; i <= D; i++)
    {
        change();
        if (a == b)
        {
            cout << i << '\n';
            return;
        }
    }
    vector<int> vis(n + 1);
    {
        vector<int> ind(n + 1);
        for (int i = 1; i <= n; i++)
        {
            ind[a[i]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            int v = a[u];
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
        for (int i = 1; i <= n; i++)
        {
            vis[i] = (ind[i] != 0);
        }
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            pre[a[i]] = i;
        }
    }
    vector<int> bel(n + 1);
    vector<int> pos(n + 1);
    vector<vector<int>> cyc;
    {
        vector<int> st(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (st[i] || !vis[i])
                continue;
            int u = i;
            vector<int> p;
            while (!st[u])
            {
                st[u] = 1;
                bel[u] = cyc.size();
                pos[u] = p.size();
                p.push_back(u);
                u = a[u];
            }
            cyc.push_back(p);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[b[i]] || bel[b[i]] != bel[a[i]])
        {

            cout << -1 << '\n';
            return;
        }
        if (b[i] != b[pre[a[i]]])
        {
            cout << -1 << '\n';
            return;
        }
        if (b[a[i]] != a[b[i]])
        {

            cout << -1 << '\n';
            return;
        }
    }

    auto calc = [&](int r, int l) -> pair<int, int>
    {
        int cur = 1, T = 0, e = -1;
        while (1)
        {
            if (cur == r && e == -1)
                e = T;
            T++;
            (cur *= 2) %= l;
            if (cur == 1)
                break;
        }
        return {e, T};
    };
    vector<pair<int, int>> op;
    for (int i = 0; i < cyc.size(); i++)
    {
        int l = cyc[i].size();
        int u = cyc[i][0];
        int d = (pos[b[u]] - pos[u] + l) % l;
        if (l == 1)
            continue;
        auto x = calc(d, l);
        if (x.first == -1)
        {
            cout << -1 << '\n';
            return;
        }
        op.push_back(x);
    }
    auto [t, m] = excrt(op);
    if (t != -1)
        cout << t + D << '\n';
    else
        cout << -1 << '\n';
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