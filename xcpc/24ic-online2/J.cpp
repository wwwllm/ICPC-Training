#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    int V = 0;
    for (auto &[w, v, c] : a)
        cin >> w >> v >> c, V += v;
    ranges::sort(a, [&](array<int, 3> &x, array<int, 3> &y)
                 { return x[0] * y[2] > y[0] * x[2]; });
    int sum = 0;
    int res1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        res1 += sum * a[i][0];
        sum += a[i][2];
    }

    cout << V - res1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}