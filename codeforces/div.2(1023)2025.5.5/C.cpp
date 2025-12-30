#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e12;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n), dp(n);
    for (auto &it : a)
        cin >> it;
    int pos = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
        {
            a[i] = -INF;
            if (pos == -1)
                pos = i;
        }
    int mx = a[0];
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] < 0)
            dp[i] = a[i];
        else
            dp[i] = dp[i - 1] + a[i];
        mx = max(mx, dp[i]);
    }
    if (mx > k || (mx != k && pos == -1))
    {
        cout << "No\n";
        return;
    }
    else
        cout << "Yes\n";
    if (pos == -1)
    {
        for (auto it : a)
            cout << it << ' ';
        cout << '\n';
        return;
    }
    int pre = 0, sum = 0;
    for (int i = pos - 1; i >= 0; i--)
    {
        sum += a[i];
        pre = max(sum, pre);
    }
    int suf = 0;
    sum = 0;
    for (int i = pos + 1; i < n; i++)
    {
        sum += a[i];
        suf = max(suf, sum);
    }
    a[pos] = -1 * (suf + pre - k);
    for (auto it : a)
        cout << it << ' ';
    cout << '\n';
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