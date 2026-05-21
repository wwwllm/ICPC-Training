#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

void solve()
{
    int n, x;
    cin >> x >> n;
    vector<int> a(n);
    for (signed i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string xx = to_string(x);
    int len = xx.size();
    vector<int> b;
    if (len > 1)
    {
        string tmp(len - 1, '0' + a.back());
        b.push_back(stoll(tmp));
    }
    else
    {
        for (auto x : a)
            b.push_back(x);
    }
    int top = a[0];
    int j = 1;
    while (!top && j < n)
    {
        top = a[j++];
    }
    if (top)
    {
        string tmp = (char)('0' + top) + string(len, '0' + a[0]);
        b.push_back(stoll(tmp));
    }
    else
        b.push_back(0);
    for (signed i = 0; i <= len; i++)
    {
        if (i == len)
        {
            b.push_back(x);
            break;
        }
        int cur = xx[i] - '0';
        int mi = -1;
        for (signed j = n - 1; j >= 0; j--)
        {
            if (a[j] < cur)
            {
                mi = a[j];
                break;
            }
        }
        if (mi != -1)
        {
            string tmp = xx.substr(0, i) + (char)(mi + '0') + string(len - 1 - i, '0' + a.back());
            b.push_back(stoll(tmp));
        }
        int ma = -1;
        for (signed j = 0; j < n; j++)
        {
            if (a[j] > cur)
            {
                ma = a[j];
                break;
            }
        }
        if (ma != -1)
        {
            string tmp = xx.substr(0, i) + (char)(ma + '0') + string(len - 1 - i, '0' + a[0]);
            b.push_back(stoll(tmp));
        }
        bool ok = 0;
        for (int x : a)
        {
            if (x == cur)
                ok = 1;
        }
        if (!ok)
            break;
    }
    int ans = 1e19;
    for (auto y : b)
    {
        int d = (y > x) ? (y - x) : (x - y);
        if (d < ans)
            ans = d;
    }
    cout << ans << '\n';
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