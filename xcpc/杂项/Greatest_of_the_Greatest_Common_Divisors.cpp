#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/problem/10482/statement/zh_cn
const int mod = 998244353, N = 1e5;
const int inf = 1e9;
struct Info
{
    int max;
    Info() : max(1) {};
    Info(int value) : max(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.max = std::max(max, other.max);
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
            info[p] = info[p] + v;
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
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector d(N + 1, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= a[i] / k; k++)
        {
            if (a[i] % k == 0)
            {
                if (a[i] / k == k)
                    d[k].push_back(i);
                else
                {
                    d[k].push_back(i);
                    d[a[i] / k].push_back(i);
                }
            }
        }
    }
    int q;
    cin >> q;
    vector<array<int, 3>> qu(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][0]--, qu[i][1]--;
        qu[i][2] = i;
    }
    vector<array<int, 3>> data;
    for (int i = 2; i <= N; i++)
    {
        if (d[i].size() <= 1)
            continue;
        int siz = d[i].size();
        for (int j = 0; j < siz - 1; j++)
        {
            int l = d[i][j], r = d[i][j + 1];
            data.push_back({l, r, i});
        }
    }
    SegTree t(n);
    ranges::sort(data, greater<>());
    ranges::sort(qu, greater<>());
    vector<int> ans(q);
    for (int i = 0, j = 0; i < q; i++)
    {
        while (j < data.size() && data[j][0] >= qu[i][0])
        {
            auto [l, r, D] = data[j];
            // cerr << qu[i][2] << ' ' << l << ' ' << r << ' ' << D << '\n';
            t.modify(r, D);
            j++;
        }
        ans[qu[i][2]] = t.query(0, qu[i][1] + 1).max;
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
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