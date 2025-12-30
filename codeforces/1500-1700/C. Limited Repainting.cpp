#include <bits/stdc++.h>
using namespace std;

//  https://codeforces.com/problemset/problem/2070/C
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '0' + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    auto cmp = [&](int x) -> bool
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > x && s[i] == 'B')
            {
                while (i <= n && (s[i] == 'B' || a[i] <= x))
                    i++;
                cnt++;
            }
        }
        return cnt <= k;
    };
    int l = -1,
        r = 1e9;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (cmp(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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