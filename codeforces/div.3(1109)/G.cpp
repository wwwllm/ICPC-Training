    #include <bits/stdc++.h>
    #define int long long
    using namespace std;

    const int inf = 1e18;
    struct Info
    {
        int max;
        Info() : max() {};
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        vector<int> dp(n + 1);
        SegTree t(n);
        for (int i = 1; i <= n; i++)
        {
            while (pq.size() && pq.top()[0] == i)
            {
                auto [_, pos] = pq.top();
                pq.pop();
                t.modify(pos, dp[pos]);
            }
            int j = max(0LL, i - a[i]);
            dp[i] = t.query(0, j).max + a[i];
            pq.push({i + a[i] + 1, i});
        }
        cout << *ranges::max_element(dp) << '\n';
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