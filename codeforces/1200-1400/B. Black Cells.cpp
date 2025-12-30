#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2026/B
// 还可以用二分，时间复杂度O(nlogk)
// 或者用前缀和优化,O(n)
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int x;
        cin >> x;
        cout << 1 << '\n';
        return;
    }
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto f = [&](vector<int> a) -> int
    {
        int m = a.size() - 1;
        int res = 0;
        for (int i = 2; i <= m; i += 2)
        {
            res = max(res, a[i] - a[i - 1]);
        }
        return res;
    };
    if (n & 1)
    {
        int res = 1e18;
        for (int i = 1; i <= n; i++)
        {
            vector<int> temp(1);
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                    temp.push_back(a[j]);
            }
            res = min(res, f(temp));
        }
        cout << res << '\n';
    }
    else
    {
        cout << f(a) << '\n';
    }
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