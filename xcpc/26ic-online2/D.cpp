#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, M = 2e6;
vector<int> p(M + 1, 1), ivp(M + 1, 1);
int exp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            (res *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return res;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void init()
{
    for (int i = 1; i <= M; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    ivp[M] = inv(p[M]);
    for (int i = M - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
inline int C(int n, int m)
{
    if (n < 0 || m < 0 || m > n)
        return 0;
    return p[n] * ivp[m] % mod * ivp[n - m] % mod;
}
void solve()
{
    int n;
    cin >> n;
    int N = 1 << n;
    vector<array<int, 2>> qu(2 * N + 1);
    {
        qu[1] = {1, N + 1};
        for (int i = 1; i < N; i++)
        {
            auto [l, r] = qu[i];
            int lson = i << 1, rson = i << 1 | 1;
            int mid = l + r >> 1;
            qu[lson] = {l, mid};
            qu[rson] = {mid, r};
        }
    }
    int q;
    cin >> q;
    vector<array<int, 2>> a(q);
    for (auto &[u, x] : a)
        cin >> u >> x;
    {
        vector<int> max(2 * N + 1, 0);
        for (auto [u, x] : a)
        {
            int cur = u;
            while (cur)
            {
                max[cur] = std::max(max[cur], x);
                cur >>= 1;
            }
        }
        for (auto [u, x] : a)
        {
            if (max[u] > x)
            {
                cout << 0 << '\n';
                return;
            }
        }
    }
    {
        vector g(N + 1, vector<int>());
        for (auto [u, x] : a)
            g[x].push_back(u);
        for (int i = 1; i <= N; i++)
        {
            if (g[i].empty())
                continue;
            ranges::sort(g[i]);
            auto [l, r] = qu[g[i][0]];
            for (int j = 1; j < g[i].size(); j++)
            {
                auto [nl, nr] = qu[g[i][j]];
                if (nl >= l && nr <= r)
                {
                    l = nl, r = nr;
                }
                else
                {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
    }
    ranges::sort(a);
    vector<int> mi(N + 1), mx(N + 1);
    for (int i = 0; i < q; i++)
    {
        auto [u, x] = a[i];
        mi[x] = u;
    }
    for (int i = q - 1; i >= 0; i--)
    {
        auto [u, x] = a[i];
        mx[x] = u;
    }
    int cnt = 0;
    vector<int> siz(2 * N + 1), vis(2 * N + 1);
    auto check = [&](int u) -> bool
    {
        while (u)
        {
            if (vis[u])
                return 0;
            u >>= 1;
        }
        return 1;
    };
    int ans = 1;
    for (int i = 1; i <= N; i++)
    {
        cnt++;
        if (!mi[i] || !mx[i])
            continue;
        if (!check(mi[i]))
        {
            cout << 0 << '\n';
            return;
        }
        vis[mi[i]] = 1;
        vis[mx[i]] = 1;
        auto [l1, r1] = qu[mi[i]];
        auto [l2, r2] = qu[mx[i]];
        int need = r2 - l2 - siz[mx[i]];
        int can = r1 - l1 - siz[mi[i]];
        if (cnt < need)
        {
            cout << 0 << '\n';
            return;
        }
        int res = can * C(cnt - 1, need - 1) % mod * p[need - 1] % mod;
        (ans *= res) %= mod;
        int u = mx[i];
        while (u)
        {
            siz[u] += need;
            u >>= 1;
        }
        cnt -= need;
    }
    (ans *= p[cnt]) %= mod;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}