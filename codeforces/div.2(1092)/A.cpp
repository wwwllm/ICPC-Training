#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    vector<int> cnt(k + 1), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }
    int cur = 0;
    for (int i = 1; i <= k; i++)
    {
        if (a[i] == 0 && cur > 0)
        {
            cout << -1 << '\n';
            return;
        }
        cur += cnt[i];
    }
    vector<int> ans;
    for (int i = k; i >= 1; i--)
    {
        int c = k + 1 - i;
        for (int j = 0; j < n; j++)
        {
            if (b[j] == i)
            {
                for (int x = 0; x < c; x++)
                {
                    ans.push_back(j + 1);
                }
            }
        }
    }
    if (ans.size() <= 1000)
    {
        cout << ans.size() << '\n';
        for (auto pos : ans)
            cout << pos << ' ';
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
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