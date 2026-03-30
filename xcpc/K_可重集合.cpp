#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
struct Info
{
    vector<int> val;
    Info() {};
    Info(int x)
    {
        val.push_back(x);
    }
    void push(int x)
    {
        val.push_back(x);
    }
};
struct SegTree
{
    int n;
    vector<Info> info;

    SegTree(int n) : n(n), info(4 * n) {};
    void modify(int p, int l, int r, int ql, int qr, int x)
    {
        if (ql <= l && r <= qr)
        {
            info[p].push(x);
            return;
        }
        if (ql >= r || qr <= l)
            return;
        int mid = l + r >> 1;
        if (ql < mid)
            modify(p << 1, l, mid, ql, qr, x);
        if (qr > mid)
            modify(p << 1 | 1, mid, r, ql, qr, x);
    }
    void modify(int l, int r, int x)
    {
        modify(1, 0, n, l, r, x);
    }
};
void solve()
{
    int n;
    cin >> n;
    SegTree T(n);
    map<int, queue<int>> mp;
    for (int i = 0; i < n; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            mp[x].push(i);
        }
        else
        {
            int l = mp[x].front(), r = i;
            mp[x].pop();
            T.modify(l, r, x);
        }
    }
    for (auto &[x, q] : mp)
    {
        while (q.size())
        {
            int l = q.front(), r = n;
            q.pop();
            T.modify(l, r, x);
        }
    }
    bitset<500005> dp;
    dp[0] = 1;
    auto dfs = [&](auto &&self, int p, int l, int r, bitset<500005> &dp) -> void
    {
        auto odp = dp;
        for (int x : T.info[p].val)
        {
            dp |= (dp << x);
        }
        if (r - l == 1)
        {
            cout << dp.count() - 1 << '\n';
            dp = odp;
            return;
        }
        int mid = l + r >> 1;
        self(self, p << 1, l, mid, dp), self(self, p << 1 | 1, mid, r, dp);
        dp = odp;
    };
    dfs(dfs, 1, 0, n, dp);
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