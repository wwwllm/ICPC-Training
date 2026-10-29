#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
const int mod = 998244353;
struct Mat
{
    int n;
    array<array<int, 4>, 4> M{{0}};
    Mat(int r) : n(r)
    {
    }
    Mat unit()
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 1;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] += M[i][k] * b.M[k][j] % mod;
                    res.M[i][j] %= mod;
                }
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << M[i][j] << " \n"[j == n - 1];
            }
        }
    }
};
struct Info
{
    Mat M;
    Info() : M(4) {};
    Info(Mat M) : M(M) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.M = other.M * M;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * _n) {};
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
    void modify(int x, Mat M)
    {
        modify(1, 0, n, x, M);
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    int N = (1LL << n);
    vector<int> st;
    vector<int> need(n);
    vector<array<int, 2>> e;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        need[v] |= 1LL << u;
        e.push_back({u, v});
    }
    auto check = [&](int mask) -> bool
    {
        for (auto [u, v] : e)
        {
            int valu = mask >> u & 1, valv = mask >> v & 1;
            if ((valu & valv) != valv)
                return 0;
        }
        return 1;
    };
    for (int mask = 0; mask < (1LL << (n - 2)); mask++)
    {
        if (check(mask << 1 | 1))
            st.push_back(mask << 1 | 1);
    }
    int cnt = st.size();
    string L, R;
    cin >> L >> R;
    int sl = L.size(), sr = R.size();
    ranges::reverse(L);
    ranges::reverse(R);
    int len = max(L.size(), R.size());
    L.resize(len, '0');
    R.resize(len, '0');
    SegTree t(len);
    vector f(4, Mat(4));
    for (int rbit = 0; rbit <= 1; rbit++)
    {
        for (int lbit = 0; lbit <= 1; lbit++)
        {
            int id = (rbit << 1) | lbit;
            for (int j = 0; j <= 1; j++)
            {
                for (int k = 0; k <= 1; k++)
                {
                    int from = (j << 1) | k;
                    for (int o = 0; o <= 1; o++)
                    {
                        for (int p = 0; p <= o; p++)
                        {
                            if (!j && o > rbit)
                                continue;

                            if (!k && p < lbit)
                                continue;
                            int tj = j | (o < rbit);
                            int tk = k | (p > lbit);
                            int to = (tj << 1) | tk;
                            int ways = (o == 1 && p == 0 ? cnt : 1);

                            f[id].M[from][to] += ways;
                            f[id].M[from][to] %= mod;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        int u = R[i] - '0', v = L[i] - '0';
        t.modify(i, f[(u << 1) | v]);
    }
    auto calc = [&]()
    {
        int res = 0;
        for (int i = 0; i < 4; i++)
        {
            (res += t.info[1].M.M[0][i]) %= mod;
        }
        cout << res << '\n';
    };
    calc();
    while (q--)
    {
        int op, pos;
        cin >> op >> pos;
        if (op == 1)
        {
            pos = sr - pos;
            R[pos] = '0' + ((R[pos] - '0') ^ 1);
        }
        else
        {
            pos = sl - pos;
            L[pos] = '0' + ((L[pos] - '0') ^ 1);
        }
        int id = (R[pos] - '0') << 1 | (L[pos] - '0');
        t.modify(pos, f[id]);
        calc();
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