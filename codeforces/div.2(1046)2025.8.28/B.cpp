#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> pos;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (s[j] == '1' && j <= n)
            j++;
        len = max(j - i, len);
        i = j;
    }
    if (len >= k)
    {
        cout << "NO\n";
        return;
    }
    else
        cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
            pos.push_back(i);
    }
    int x = n;
    vector<int> ans(n + 1);
    for (auto i : pos)
        ans[i] = x--;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
            ans[i] = x--;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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