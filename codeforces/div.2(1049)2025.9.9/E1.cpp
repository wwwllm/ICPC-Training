#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int cnt1(int x)
{
    return __builtin_popcount(x);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++)
        cin >> p[i];
    if (m == 1)
    {
        cout << 1 << '\n';
        return;
    }
    vector<int> dp((1LL << n));
    vector<int> val(n, 1);
    auto findbit = [&](int mask, int c)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1LL << i))
            {
                cnt++;
                if (cnt == c)
                    return i;
            }
        }
        return -1LL;
    };
    auto getcnt = [&](auto &&self, int mask) -> int
    {
        if (dp[mask] != -1)
            return dp[mask];
        int cnt = cnt1(mask);
        if (cnt == 1)
        {
            int idx = __builtin_ctz(mask);
            return dp[mask] = val[idx];
        }
        bool ok = ((n - cnt) % 2 == 0);

        if (ok)
        {
            int v = 1;
            for (int c : p)
            {
                if (c > p)
                    break;
                int idx = findbit(mask, c);
                int newmask = mask ^ (1 << idx);
                int child = getcnt(getcnt, newmask);
                if (child > v)
                    v = child;
                if (v == 2)
                    break;
            }
            dp[mask] = v;
        }
        else
        {
            int v = 2;
            for (int c : p)
            {
                if (c > p)
                    break;
                int idx = findbit(mask, c);
                int newmask = mask ^ (1 << idx);
                int child = getcnt(getcnt, newmask);
                if (child < v)
                    v = child;
                if (v == 1)
                    break;
            }
            dp[mask] = best;
        }
        return dp[mask];
    };
    int ans = 0;
    for (int q = 1; q < (1LL << n); q++)
    {
        vector<int> bit(n);
        for (int k = 0; k < n; k++)
            bit[k] = ((q >> k) & 1) + 1;
        ans = (ans + getcnt(getcnt, (1LL << n) - 1)) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}