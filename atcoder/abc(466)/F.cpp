#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, ma;
    cin >> n >> ma;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        if (b.empty() || a[i] < b.back())
            b.push_back(a[i]);
    }
    int m = b.size();
    vector<int> cnt(m);
    auto calc = [&](auto &&self, int pos, int x) -> int
    {
        if (x == 0 || pos >= m)
            return 0;
        int idx = ranges::lower_bound(b, x, greater<int>()) - b.begin();
        if (idx == m)
            return 0;
        int q = x / b[idx], r = x % b[idx];
        return q * cnt[idx] + self(self, idx, r);
    };
    for (int i = m - 1; i >= 0; i--)
    {
        cnt[i] = 1 + calc(calc, i + 1, b[i] - 1);
    }
    cout << calc(calc, 0, ma) << '\n';
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