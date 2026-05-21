#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
const int N = 63;
void solve()
{
    int m, k;
    cin >> m >> k;

    vector dp(N + 1, vector<int>(N + 1, -1));
    auto calc = [&](auto &&self, int pos, int cnt, bool lim, bitset<N> bit) -> int
    {
        if (cnt < 0)
            return 0;
        if (pos < 0)
            return cnt == 0 ? 1 : 0;
        if (!lim && dp[pos][cnt] != -1)
            return dp[pos][cnt];
        int up = lim ? bit[pos] : 1;
        int res = 0;
        for (int i = 0; i <= up; i++)
        {
            res += self(self, pos - 1, cnt - (i == 1), lim && (i == up), bit);
        }
        if (!lim)
            dp[pos][cnt] = res;
        return res;
    };
    auto check = [&](int x) -> bool
    {
        return calc(calc, 62, k, 1, bitset<N>(2 * x)) - calc(calc, 62, k, 1, bitset<N>(x)) >= m;
    };
    int l = -1, r = 4e18;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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