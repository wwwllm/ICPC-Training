#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = n & 1 ? n - 1 : n - 2;

    vector<int> suf1(n + 2, inf), suf0(n + 2, -inf);
    for (int i = n; i >= 1; i--)
    {
        if (i & 1)
        {
            suf1[i] = min(suf1[i + 1], 2 * a[i] - i);
            suf0[i] = suf0[i + 1];
        }
        else
        {
            suf1[i] = suf1[i + 1];
            suf0[i] = max(suf0[i + 1], 2 * a[i] + i);
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << suf1[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << suf0[i] << " \n"[i == n];
    // }
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            res = max(res, suf0[i] - 2 * a[i] - i);
        }
        else
        {
            res = max(res, -suf1[i] + 2 * a[i] - i);
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            sum += a[i];
        else
            sum -= a[i];
    }
    cout << sum + res << '\n';
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