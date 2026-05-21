#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    int t = (x + y) / n;
    int mid = (x + y) % n;
    array<int, 3> cpre = {0, 0, 0}, csuf = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        if (i < mid)
            cpre[s[i]]++;
        else
            csuf[s[i]]++;
    }
    if (t == 0)
    {
        int p = cpre[2];
        auto ans = s;
        for (int i = 0; i < mid; i++)
        {
            if (ans[i] == 2 && p > 0)
            {
                ans[i] = 0;
                p--;
            }
            else if (ans[i] == 2)
            {
                ans[i] = 1;
            }
        }
        for (int i = mid; i < n; i++)
        {
            if (ans[i] == 2)
                ans[i] = 0;
        }
        int xx = 0, yy = 0;
        for (int i = 0; i < mid; i++)
        {
            if (ans[i] == 0)
                xx++;
            else if (ans[i] == 1)
                yy++;
        }
        if (x != xx || y != yy)
        {
            cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << '\n';
        return;
    }
    else
    {
        for (int i = cpre[2]; i >= 0; i--)
        {
            int prex = cpre[0] + i, prey = cpre[1] + (cpre[2] - i);
            int rx = x - prex * (t + 1), ry = y - prey * (t + 1);
            if (rx < csuf[0] * t || ry < csuf[1] * t || rx % t != 0 || ry % t != 0)
                continue;
            int xx = rx / t, yy = ry / t;
            if (xx + yy == (n - mid))
            {
                int p = i;
                auto ans = s;
                for (int i = 0; i < mid; i++)
                {
                    if (p && ans[i] == 2)
                    {
                        ans[i] = 0;
                        p--;
                    }
                    else if (ans[i] == 2)
                        ans[i] = 1;
                }
                p = xx - csuf[0];
                for (int i = mid; i < n; i++)
                {
                    if (p && ans[i] == 2)
                    {
                        ans[i] = 0;
                        p--;
                    }
                    else if (ans[i] == 2)
                        ans[i] = 1;
                }
                for (int i = 0; i < n; i++)
                    cout << ans[i];
                cout << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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