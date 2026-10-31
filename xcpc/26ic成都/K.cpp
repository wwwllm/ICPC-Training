#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), len(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> len[i];
    }
    auto check = [&](int x) -> bool
    {
        int L = a[1] - x, R = a[1] + x;
        for (int i = 2; i <= n; i++)
        {
            int hi = a[i] + x, lo = a[i] - x;
            int up = min(R - len[i], hi);
            int down = max(L + len[i], lo);
            int nl = inf, nr = -inf;
            if (lo <= up)
            {
                nl = min(nl, lo);
                nr = max(nr, up);
            }
            if (hi >= down)
            {
                nl = min(nl, down);
                nr = max(nr, hi);
            }
            if (nl > nr)
                return 0;
            L = nl, R = nr;
        }
        return 1;
    };
    // assert(0);
    int l = -1, r = inf;
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