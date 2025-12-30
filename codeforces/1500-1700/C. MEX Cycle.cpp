#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n);
    if (x > y)
        swap(x, y);
    ans[x - 1] = 1, ans[y - 1] = 0;
    int p = x;
    while (p != y - 1)
    {
        ans[p] = !ans[p - 1];
        if (p == y - 2)
        {
            if (ans[p] == ans[p + 1])
                ans[p] = 2;
        }
        p++;
    }
    p = (p + 1) % n;
    while (p != x - 1)
    {
        ans[p] = !ans[(p - 1 + n) % n];
        p = (p + 1) % n;
        if (p == x - 1)
        {
            if (ans[p] == ans[(p - 1 + n) % n])
                ans[(p - 1 + n) % n] = 2;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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