#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1982/C
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        int res = 0;
        j = i;
        while (j < n && res < l)
        {
            res += a[j++];
        }
        if (res >= l && res <= r)
        {
            ans++;
            i = j - 1;
        }
        else if (res >= l)
        {
            while (i < j && res > r)
            {
                res -= a[i++];
            }
            if (res >= l)
                ans++, i = j - 1;
            else
                i--;
        }
        else
            break;
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