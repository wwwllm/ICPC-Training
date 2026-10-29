#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
struct Info
{
    int cnt = 0;
    int sumx = 0, sumy = 0, sumxy = 0;
};
void solve()
{
    int n, d;
    cin >> n >> d;

    map<array<int, 3>, Info> mp;
    auto dfs = [&](auto &&self, int pos, int c, int b) -> Info
    {
        if (pos == 61)
        {
            if (c == 0 && b == 0)
            {
                return {1, 0, 0, 0};
            }
            return Info{};
        }
        if (mp.count({pos, c, b}))
            return mp[{pos, c, b}];
        Info res;
        int nbit = (n >> pos) & 1;
        int dbit = (d >> pos) & 1;
        for (int x = 0; x < 2; x++)
        {
            int s = x + dbit + c;
            int y = s % 2;
            int nc = s / 2;
            int nb = (nbit - x - b < 0);

            Info nxt = self(self, pos + 1, nc, nb);

            res.cnt = (res.cnt + nxt.cnt) % mod;
            res.sumx = (res.sumx + nxt.sumx + nxt.cnt * x) % mod;
            res.sumy = (res.sumy + nxt.sumy + nxt.cnt * y) % mod;
            res.sumxy = (res.sumxy + nxt.sumxy + nxt.sumx * y % mod + nxt.sumy * x % mod + nxt.cnt * x * y % mod) % mod;
        }
        return mp[{pos, c, b}] = res;
    };
    auto res = dfs(dfs, 0, 0, 0);
    cout << res.sumxy << '\n';
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