#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    int k;
    cin >> k >> s;
    int n = s.size();
    vector<vector<int>> pre(n, vector<int>(26, 0));
    pre[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            pre[i][j] = pre[i - 1][j];
        pre[i][s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int u = s[i] - 'a';
        if (pre[n - 1][u] - pre[i][u] > 0)
            ans = max(i + 1, ans);
    }
    for (int i = n - 2; i > 0; i--)
    {
        int u = s[i] - 'a';
        if (pre[i - 1][u] > 0)
        {
            ans = max(n - i, ans);
        }
    }
    cout << ans << '\n';
}