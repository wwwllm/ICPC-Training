#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 1; j < m; j++)
    //     {
    //         int x = a[i] ^ b[j];
    //         if ((a[i] ^ b[j + 1]) == x + 1 && (a[i + 1] ^ b[j]) == x + 2 && (a[i + 1] ^ b[j + 1]) == x + 3)
    //         {
    //             cerr << i << ' ' << j << '\n';
    //         }
    //     }
    // }
    vector<map<int, int>> cnt(31);
    for (int i = 1; i < m; i++)
    {
        if ((b[i] ^ b[i + 1]) == 1)
        {
            for (int l = 0; l < 30; l++)
            {
                cnt[l][b[i] & ((1 << (l + 1)) - 1)]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int l = 1; l < 30; l++)
        {
            int d = ((1 << l) - 1) << 1;
            if ((a[i] ^ a[i + 1]) == d)
            {
                int x = ((1 << (l - 1)) - 1) << 1;
                int tar = (a[i] ^ x) & ((1 << (l + 1)) - 1);
                ans += cnt[l][tar];
            }
        }
    }
    cout << ans << '\n';
    // int cnt = 1;
    // for (int i = 10; i < 100; i++)
    // {
    //     for (int j = 10; j < 100; j++)
    //     {
    //         for (int u = 10; u < 100; u++)
    //         {
    //             for (int v = 10; v < 100; v++)
    //             {
    //                 int x = u ^ i;
    //                 if ((u ^ j) == x + 1 && (v ^ i) == x + 2 && (v ^ j) == x + 3)
    //                 {
    //                     cout << cnt++ << ":" << '\n';
    //                     cout << i << ' ' << j << '\n'
    //                          << u << ' ' << v << '\n';
    //                 }
    //             }
    //         }
    //     }
    // }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}