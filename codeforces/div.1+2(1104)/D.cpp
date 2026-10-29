#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (a[i] == 1 ? 1 : 2);
        pre[i] %= 3;
    }
    array<int, 3> cur = {1, 0, 0};
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = pre[i];
        cur[u]++;
        ans += cur[(u + 1) % 3] + cur[(u + 2) % 3];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            a[i] ^= 1;
        }
    }
    for (int i = 1; i <= n;)
    {
        int j = i;
        while (j <= n && a[j] == a[i])
        {
            j++;
        }
        int len = j - i;
        ans -= (len / 2) * ((len - 1) / 2);
        i = j;
    }
    cout << ans << '\n';
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