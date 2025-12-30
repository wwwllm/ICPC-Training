#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    d[1] = 0;
    vector<int> dl(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        dl[i] = cnt;
        if (d[i] > 0)
            cnt++;
        else
            cnt = 0;
    }
    vector<int> dr(n + 1);
    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        dr[i] = cnt;
        if (d[i] > 0)
            cnt++;
        else
            cnt = 0;
    }
    vector<int> dl2(n + 1);
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        dl2[i] = cnt;
        if (d[i] < 0)
            cnt++;
        else
            cnt = 0;
    }
    vector<int> dr2(n + 1);
    cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        dr2[i] = cnt;
        if (d[i] < 0)
            cnt++;
        else
            cnt = 0;
    }
    int ans = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        if (d[i] > 0 and dr2[i] > 0 and i + dr2[i] != n)
        {
            ans += (1 + dl[i]) * (1 + dr[i + dr2[i] + 1]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
