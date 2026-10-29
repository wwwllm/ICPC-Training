#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct ST
{
    int n, K;
    vector<vector<int>> st;
    vector<int> lg;
    ST() {}
    ST(int n)
    {
        vector<int> a(n, inf);
        init(a);
    }
    ST(vector<int> &a)
    {
        init(a);
    }
    void init(vector<int> &a)
    {
        n = a.size();
        lg.resize(n + 1);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i >> 1] + 1;
        int K = lg[n] + 1;
        st.assign(K, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            st[0][i] = a[i];
        }
        for (int k = 1; k < K; k++)
        {
            for (int i = 0; i + (1LL << k) <= n; i++)
            {
                st[k][i] = min(st[k - 1][i],
                               st[k - 1][i + (1LL << (k - 1))]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = lg[r - l];
        return min(st[k][l], st[k][r - (1LL << k)]);
    }
};
void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<array<int, 2>> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    vector dp(m + 1, vector<int>(n + 1, inf));
    dp[0][s] = 0;
    for (int i = 1; i <= m; i++)
    {
        auto [k, cost] = a[i];
        vector ndp(m + 1, vector<int>(n + 1, inf));
        ST T0(n + 1);
        for (int c = 0; c <= i; c++)
        {
            ST T1(dp[c]);
            for (int t = 1; t <= n; t++)
            {
                int l = max(1LL, t - (k - 1)), r = min(n, t + (k - 1));
                ndp[c][t] = min(ndp[c][t], T1.query(l, r + 1));
                for (int d : {-k, k})
                {
                    int tt = t + d;
                    if (tt >= 1 && tt <= n)
                    {
                        ndp[c][t] = min(ndp[c][t], dp[c][tt] + cost);
                    }
                }
            }
            ndp[c][1] = min(ndp[c][1], T0.query(1, k + 1) + cost);
            ndp[c][n] = min(ndp[c][n], T0.query(n - k + 1, n + 1) + cost);
            T0 = T1;
        }
        dp = ndp;
    }
    for (int t = 1; t <= n; t++)
    {
        int mx;
        cin >> mx;
        int res = -1;
        for (int c = 0; c <= m; c++)
        {
            if (dp[c][t] <= mx)
            {
                res = max(res, c);
            }
        }
        cout << res << " \n"[t == n];
    }
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
