#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> ans(n);
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + k) % n;
        if (p[j] == x)
        {
            pos = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = (i + pos) % n;
        ans[i] = p[j];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}