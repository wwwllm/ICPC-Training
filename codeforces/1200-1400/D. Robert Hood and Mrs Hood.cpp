#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2014/D
void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> a(n + 2);
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;
        a[max(1LL, l - d + 1)]++;
        a[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    int mi = 0x3f3f3f3f, ma = 0;
    int dmi = 0, dma = 0;
    for (int i = 1; i - 1 + d <= n; i++)
    {
        if (a[i] < mi)
        {
            mi = a[i];
            dmi = i;
        }
        if (a[i] > ma)
        {
            ma = a[i];
            dma = i;
        }
    }
    cout << dma << ' ' << dmi << '\n';
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