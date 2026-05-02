#include <bits/stdc++.h>
#define int long long
using namespace std;
using u64 = unsigned long long;

// https://codeforces.com/gym/105423
const int base = 13331, N = 1e5;
vector<u64> p(N + 1);
void init()
{
    p[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * base;
}
struct Info
{
    u64 hash;
    int cnt;
    Info() : hash(0), cnt(0) {};
    Info(u64 value, int c) : hash(value), cnt(c) {};
    Info operator+(const Info &other) const
    {
        return {hash * p[other.cnt] + other.hash, cnt + other.cnt};
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v, int c)
    {
        modify(1, 0, n, x, Info(v, c));
    }
};
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
u64 get_rand()
{
    return rng();
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
    vector<int> posb(n + 1), posa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        posb[b[i]] = i;
        posa[a[i]] = i;
    }
    SegTree ta(n + 1), tb(n + 1);
    int ans = 0;
    for (int r = 1, l = 1; r <= n; r++)
    {
        ta.modify(posa[r], r, 1);
        tb.modify(posb[r], r, 1);
        while (tb.query(0, n + 1).hash != ta.query(0, n + 1).hash)
        {
            ta.modify(posa[l], 0, 0);
            tb.modify(posb[l], 0, 0);
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}