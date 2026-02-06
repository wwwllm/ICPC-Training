#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), ne(n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i])
            m++;
        ne[i] = max(ne[i - 1], a[i] + i);
    }
    if (m <= k)
    {
        cout << 0 << '\n';
        return;
    }
    auto check = [&](int x) -> bool
    {
        int i = 1;
        while (i <= n && a[i] == 0)
            i++;
        int cnt = 1;
        int ti = 0;
        while (i <= n)
        {
            ti++;
            i = ne[i];
            if (i >= n)
                break;
            if (i == ne[i])
            {
                while (i <= n && i == ne[i])
                    i++;
                if (i <= n)
                    ti = 0;
                cnt++;
            }
            else
            {
                if (ti == x)
                {
                    i++;
                    while (i <= n && a[i] == 0)
                        i++;
                    if (i <= n)
                        ti = 0;
                    cnt++;
                }
            }
        }
        return cnt <= k;
    };
    int l = 0, r = n;
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    if (!check(r))
        cout << -1 << '\n';
    else
        cout << r << '\n';
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