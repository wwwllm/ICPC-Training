#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1996/C
void solve()
{
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;
    vector<vector<int>> cnt(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++)
    {
        int u = a[i] - 'a', v = b[i] - 'a';
        if (i > 0)
        {
            for (int j = 0; j < 26; j++)
            {
                cnt[i][j] = cnt[i - 1][j];
            }
        }
        cnt[i][u]++, cnt[i][v]--;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            res += abs(cnt[r][i] - cnt[l - 1][i]);
        }
        cout << (res + 1) / 2 << '\n';
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