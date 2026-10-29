#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    int ans = 0;
    vector<int> d;
    auto sum = [&](int x)
    {
        return x * (x + 1) / 2;
    };
    auto calc = [&](int len, int c) -> int
    {
        int cnt = c + 1;
        int m = len - c;
        int q = m / cnt, r = m % cnt;
        return m * 20 + 5 * (cnt - r) * sum(q) + 5 * r * sum(q + 1);
    };
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (j <= n && a[j] == 0)
            j++;
        int l = j - i;
        int pre = 20 * l + 5 * sum(l);
        ans += pre;
        i = j;
        for (int c = 1; c <= l; c++)
        {
            int val = calc(l, c);
            d.push_back(pre - val);
            pre = val;
        }
    }
    ranges::sort(d, greater<int>());
    for (int i = 0; i < min(k, (int)d.size()); i++)
        ans -= d[i];
    cout << ans << '\n';
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