#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;

// 使用高精度时钟作为随机数种子，防止被针对性的测试数据 hack
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 获取一个随机的 64 位整数
u64 get_random()
{
    return rng();
}
const int mod = 998244353;
struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
    };
    vector<int> root;
    int tot;
    int n; // 值域
    vector<Node> info;
    SegTree(int n, int nodes, int ver) : n(n), tot(0)
    {
        info.assign(nodes, {0, 0, 0});
        root.assign(ver + 1, 0);
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = (info[l].cnt + info[r].cnt) % mod;
    }

    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];

        if (r - l == 1)
        {
            (info[p].cnt += v) %= mod;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int ver, int pre_ver, int x, int v = 1)
    {
        modify(root[ver], root[pre_ver], 0, n, x, v);
    }

    int query_cnt(int L, int R, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return 0;
        if (x <= l && r <= y)
            return (info[R].cnt - info[L].cnt + mod) % mod;
        int mid = l + r >> 1;
        return query_cnt(info[L].l, info[R].l, l, mid, x, y) + query_cnt(info[L].r, info[R].r, mid, r, x, y);
    }
    int query_cnt(int L, int R, int l, int r)
    {
        return query_cnt(root[L], root[R], 0, n, l, r);
    }
    int query_rank(int L, int R, int x)
    {
        return query_cnt(root[L], root[R], 0, n, 0, x) + 1;
    }
    int kth(int L, int R, int l, int r, int k)
    {
        if (r - l == 1)
            return l;
        int mid = l + r >> 1;

        int cntl = info[info[R].l].cnt - info[info[L].l].cnt;

        if (k <= cntl)
        {
            return kth(info[L].l, info[R].l, l, mid, k);
        }
        else
        {
            return kth(info[L].r, info[R].r, mid, r, k - cntl);
        }
    }
    int kth(int L, int R, int k)
    {
        return kth(root[L], root[R], 0, n, k);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> L(n + 1);
    vector pos(n + 1, vector<int>());
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        pos[a[i]].push_back(i);
        int s = pos[a[i]].size();
        if (s > 4)
        {
            int l = pos[a[i]][s - 5];
            cur = max(l, cur);
        }
        L[i] = cur;
    }
    vector<array<u64, 2>> hash(n + 1);
    for (int i = 1; i <= n; i++)
    {
        hash[i] = {get_random(), get_random()};
    }
    vector<int> cnt(n + 1);
    vector<u64> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
        pre[i] = hash[a[i]][cnt[a[i]] & 1];
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] ^= pre[i - 1];
    }
    vector<u64> b;
    for (int i = 0; i <= n; i++)
    {
        b.push_back(pre[i]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    auto find = [&](u64 x) -> int
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    SegTree t(b.size() + 1, (n + 1) * 20, n + 1);
    vector<int> dp(n + 1);
    dp[0] = 1;
    t.modify(1, 0, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        int l = L[i];
        int pos = find(pre[i]);
        dp[i] = t.query_cnt(l, i, pos, pos + 1);
        t.modify(i + 1, i, pos, dp[i]);
    }
    cout << dp[n] << '\n';
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