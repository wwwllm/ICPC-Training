#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        sum[i] = a[i] + sum[i - 1];
    }
    map<int, int> mp;
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(sum[i - 1]);
        if (a[i] > x)
        {
            mp.clear();
            while (q.size())
                q.pop();
        }
        else if (a[i] == x)
        {
            while (!q.empty())
            {
                auto su = q.front();
                q.pop();
                mp[su]++;
            }
        }
        int cnt = mp[sum[i] - s];
        ans += cnt;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}