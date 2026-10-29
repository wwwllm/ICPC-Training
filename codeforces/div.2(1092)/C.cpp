#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    array<int, 2> p;
    cin >> p[0] >> p[1];
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> d(n + 2);
    ranges::sort(p);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int a1 = a[i] % p[0], a2 = (a[i] % p[1]) % p[0];
        d[i] = a2 - a1;
        sum += a1;
    }
    auto calc = [&]() -> int
    {
        int res1 = sum;
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + d[i];
        }
        vector<int> suf(n + 2);
        for (int i = n; i >= 1; i--)
        {
            suf[i] = suf[i + 1] + min(0LL, d[i]);
        }
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i + k;
            if (j <= n + 1)
            {
                int tmp = min(0LL, pre[j - 1] - pre[i - 1]) + suf[j] + cur;
                res1 = min(res1, sum + tmp);
            }
            cur += min(0LL, d[i]);
        }
        return res1;
    };
    cout << calc() << '\n';
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