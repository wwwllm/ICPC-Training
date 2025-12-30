#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2009/E
void solve()
{
    int n, k;
    cin >> n >> k;
    auto f = [&](int l, int r) -> int
    { return (l + r) * (r - l + 1) / 2; };
    int l = k - 1, r = n + k;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (f(k, mid) - f(mid + 1, k + n - 1) >= 0)
            r = mid;
        else
            l = mid;
    }
    int res1 = abs(f(k, r) - f(r + 1, k + n - 1));
    int res2 = abs(f(k, l) - f(l + 1, k + n - 1));
    cout << min(res1, res2) << '\n';
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